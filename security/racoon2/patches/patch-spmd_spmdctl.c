$NetBSD: patch-spmd_spmdctl.c,v 1.1 2018/05/29 01:22:50 christos Exp $

- Fix inefficient snprintfs, and detect errors.
- Fix wrong memset length

*** spmd/spmdctl.c.orig	Sun Mar 28 21:52:00 2010
--- spmd/spmdctl.c	Mon May 28 14:17:08 2018
***************
*** 38,43 ****
--- 38,44 ----
  #include <netdb.h>
  #include <netinet/tcp.h>
  #include <signal.h>
+ #include <stdarg.h>
  #include <errno.h>
  #include "spmd_includes.h"
  #include "spmd_internal.h"
***************
*** 154,159 ****
--- 155,176 ----
  	return len;
  }
  
+ static ssize_t __attribute__((__format__(__printf__, 2, 3)))
+ sc_writestr(int fd, const char *fmt, ...)
+ {
+ 	char buf[2048];
+ 	va_list ap;
+ 	va_start(ap, fmt);
+ 	int len = vsnprintf(buf, sizeof(buf), fmt, ap);
+ 	va_end(ap);
+ 	if (len == -1) {
+ 		perror("sc_writestr");
+ 		return -1;
+ 	}
+ 
+ 	return sc_writemsg(fd, buf, (size_t)len);
+ }
+ 
  static int
  sc_getline(int fd, char *buf, int len)
  {
***************
*** 247,253 ****
  sc_parse_alloc_sp_entry(const char *str, struct sp_entry *pre)
  {
  	char *ap, *cp;
! 	size_t slid_len=0, len=0;
  	struct sp_entry *sd=NULL;
  
  	sd = malloc(sizeof(*sd));
--- 264,270 ----
  sc_parse_alloc_sp_entry(const char *str, struct sp_entry *pre)
  {
  	char *ap, *cp;
! 	size_t slid_len=0;
  	struct sp_entry *sd=NULL;
  
  	sd = malloc(sizeof(*sd));
***************
*** 261,267 ****
  	sd->sa_dst = (struct sockaddr *)&sd->ss_sa_dst;
  
  	if (str) {
- 		len = strlen(str);
  		ap = (char *)str;
  		cp = strpbrk(ap, " ");
  		if (!cp) {
--- 278,283 ----
***************
*** 575,581 ****
  sc_setup_pfkey(struct rcpfk_msg *rc)
  {
  
! 	memset(rc, 0, sizeof(rc));
  	memset(&pfkey_cbs, 0, sizeof(pfkey_cbs));
  	pfkey_cbs.cb_spddump = &sc_spddump_cb;
  
--- 591,597 ----
  sc_setup_pfkey(struct rcpfk_msg *rc)
  {
  
! 	memset(rc, 0, sizeof(*rc));
  	memset(&pfkey_cbs, 0, sizeof(pfkey_cbs));
  	pfkey_cbs.cb_spddump = &sc_spddump_cb;
  
***************
*** 657,665 ****
  sc_policy(int s, char *selector_index, uint64_t lifetime, sa_mode_t samode, 
  	const char *sp_src, const char *sp_dst, const char *sa_src, const char *sa_dst, int flag)
  {
- 	char wbuf[BUFSIZ];
  	char rbuf[BUFSIZ];
- 	int w;
  	char sl[512]; /* XXX */
  	char lt[32];
  	int ps;
--- 673,679 ----
***************
*** 669,697 ****
  
  	if (flag == TYPE_POLICY_ADD) {
  		if (samode == SA_MODE_TRANSPORT) {
  			snprintf(sl, sizeof(sl), "%s", selector_index);
  			snprintf(lt, sizeof(lt), "%" PRIu64, lifetime);
! 			snprintf(wbuf, sizeof(wbuf), "POLICY ADD %s %s TRANSPORT %s %s\r\n",
! 					sl, lt, sp_src, sp_dst);
! 			w= sc_writemsg(s, wbuf, strlen(wbuf));
! 		}
! 		else if (samode == SA_MODE_TUNNEL) {
! 			return -1;
! 			snprintf(sl, sizeof(sl), "%s", selector_index);
! 			snprintf(lt, sizeof(lt), "%" PRIu64, lifetime);
! 			snprintf(wbuf, sizeof(wbuf), "POLICY ADD %s %s TUNNEL %s %s %s %s\r\n",
! 					sl, lt, sp_src, sp_dst, sa_src, sa_dst);
! 			w= sc_writemsg(s, wbuf, strlen(wbuf));
  		} else {
  			return -1;
  		}
  	} else if (flag == TYPE_POLICY_DEL) {
! 		snprintf(sl, sizeof(sl), "%s", selector_index);
! 		snprintf(wbuf, sizeof(wbuf), "POLICY DELETE %s\r\n", sl);
! 		w= sc_writemsg(s, wbuf, strlen(wbuf));
  	} else if (flag == TYPE_POLICY_DUMP) {
! 		snprintf(wbuf, sizeof(wbuf), "POLICY DUMP\r\n");
! 		w= sc_writemsg(s, wbuf, strlen(wbuf));
  		goto dump;
  	} else {
  		return -1;
--- 683,710 ----
  
  	if (flag == TYPE_POLICY_ADD) {
  		if (samode == SA_MODE_TRANSPORT) {
+ 			if (sc_writestr(s,
+ 			    "POLICY ADD %s %" PRIu64 " TRANSPORT %s %s\r\n",
+ 			    selector_index, lifetime, sp_src, sp_dst) < 0)
+ 				return -1;
+ 		} else if (samode == SA_MODE_TUNNEL) {
  			snprintf(sl, sizeof(sl), "%s", selector_index);
  			snprintf(lt, sizeof(lt), "%" PRIu64, lifetime);
! 			if (sc_writestr(s,
! 			    "POLICY ADD %s %" PRIu64 " TUNNEL %s %s %s %s\r\n",
! 			    selector_index, lifetime, sp_src, sp_dst, sa_src,
! 			    sa_dst) < 0)
! 				return -1;
! 
  		} else {
  			return -1;
  		}
  	} else if (flag == TYPE_POLICY_DEL) {
! 		if (sc_writestr(s, "POLICY DELETE %s\r\n", selector_index) < 0)
! 			return -1;
  	} else if (flag == TYPE_POLICY_DUMP) {
! 		if (sc_writestr(s, "POLICY DUMP\r\n") < 0)
! 			return -1;
  		goto dump;
  	} else {
  		return -1;
***************
*** 752,768 ****
  sc_migrate(int s, char *selector_index, const char *src0, const char *dst0,
  	const char *src, const char *dst)
  {
- 	char wbuf[BUFSIZ];
  	char rbuf[BUFSIZ];
- 	int w;
- 	char sl[512]; /* XXX */
- 
- 	snprintf(sl, sizeof(sl), "%s", selector_index);
- 	snprintf(wbuf, sizeof(wbuf),
- 		 "MIGRATE %s %s %s %s %s\r\n",
- 		 sl, src0, dst0, src, dst);
- 	w = sc_writemsg(s, wbuf, strlen(wbuf));
  
  	if (sc_getline(s, rbuf, sizeof(rbuf)) < 0) {
  		fprintf(stderr, "can't get response from spmd\n");
  		return -1;
--- 765,775 ----
  sc_migrate(int s, char *selector_index, const char *src0, const char *dst0,
  	const char *src, const char *dst)
  {
  	char rbuf[BUFSIZ];
  
+ 	if (sc_writestr(s, "MIGRATE %s %s %s %s %s\r\n",
+ 	     selector_index, src0, dst0, src, dst) < 0)
+ 		return -1;
  	if (sc_getline(s, rbuf, sizeof(rbuf)) < 0) {
  		fprintf(stderr, "can't get response from spmd\n");
  		return -1;
***************
*** 777,786 ****
  static int
  sc_status(int s)
  {
- 	int w;
  	char rbuf[512];
  
! 	w = sc_writemsg(s, "STAT\r\n", strlen("STAT\r\n"));
  	while ( sc_getline(s, rbuf, sizeof(rbuf)) > 0) {
  		if (rbuf[0] != '2')
  			return -1;
--- 784,793 ----
  static int
  sc_status(int s)
  {
  	char rbuf[512];
  
! 	if (sc_writestr(s, "STAT\r\n") < 0)
! 		return -1;
  	while ( sc_getline(s, rbuf, sizeof(rbuf)) > 0) {
  		if (rbuf[0] != '2')
  			return -1;
***************
*** 795,803 ****
  static int
  sc_ns(int s, char *addr, int flag)
  {
- 	int w;
  	char rbuf[512];
- 	char wbuf[512];
  	char naddr[NI_MAXHOST];
  	int match=0;
  
--- 802,808 ----
***************
*** 811,817 ****
  
  
  	if (flag == TYPE_NS_ADD) {
! 		w = sc_writemsg(s, "NS LIST\r\n", strlen("NS LIST\r\n"));
  		while ( sc_getline(s, rbuf, sizeof(rbuf)) > 0) {
  			if (rbuf[0] != '2')
  				return -1;
--- 816,823 ----
  
  
  	if (flag == TYPE_NS_ADD) {
! 		if (sc_writestr(s, "NS LIST\r\n") < 0)
! 			return -1;
  		while ( sc_getline(s, rbuf, sizeof(rbuf)) > 0) {
  			if (rbuf[0] != '2')
  				return -1;
***************
*** 823,838 ****
  		}
  
  		if (match) {
! 			snprintf(wbuf, sizeof(wbuf), "NS CHANGE %s\r\n", naddr);
! 			w= sc_writemsg(s, wbuf, strlen(wbuf));
  		} else {
! 			snprintf(wbuf, sizeof(wbuf), "NS ADD %s\r\n", naddr);
! 			w= sc_writemsg(s, wbuf, strlen(wbuf));
  		}
  		return 0;
  	} else if (flag == TYPE_NS_DEL) {
  		int lines=0;
! 		w = sc_writemsg(s, "NS LIST\r\n", strlen("NS LIST\r\n"));
  		while ( sc_getline(s, rbuf, sizeof(rbuf)) > 0) {
  			if (rbuf[0] != '2')
  				return -1;
--- 829,845 ----
  		}
  
  		if (match) {
! 			if (sc_writestr(s, "NS CHANGE %s\r\n", naddr) < 0)
! 				return -1;
  		} else {
! 			if (sc_writestr(s, "NS ADD %s\r\n", naddr) < 0)
! 				return -1;
  		}
  		return 0;
  	} else if (flag == TYPE_NS_DEL) {
  		int lines=0;
! 		if (sc_writestr(s, "NS LIST\r\n") < 0)
! 			return -1;
  		while ( sc_getline(s, rbuf, sizeof(rbuf)) > 0) {
  			if (rbuf[0] != '2')
  				return -1;
***************
*** 845,856 ****
  		}
  
  		if (match && lines >1) {
! 			snprintf(wbuf, sizeof(wbuf), "NS DELETE %s\r\n", naddr);
! 			w= sc_writemsg(s, wbuf, strlen(wbuf));
  		}
  		return 0;
  	} else if (flag == TYPE_NS_LST) {
! 		sc_writemsg(s, "NS LIST\r\n", strlen("NS LIST\r\n"));
  		while ( sc_getline(s, rbuf, sizeof(rbuf)) > 0) {
  			if (rbuf[0] != '2')
  				return -1;
--- 852,864 ----
  		}
  
  		if (match && lines >1) {
! 			if (sc_writestr(s, "NS DELETE %s\r\n", naddr) < 0)
! 				return -1;
  		}
  		return 0;
  	} else if (flag == TYPE_NS_LST) {
! 		if (sc_writestr(s, "NS LIST\r\n") < 0)
! 			return -1;
  		while ( sc_getline(s, rbuf, sizeof(rbuf)) > 0) {
  			if (rbuf[0] != '2')
  				return -1;
***************
*** 977,983 ****
  {
  	char rbuf[512];
  	char wbuf[512];
! 	int r,w;
  	int s = -1;
  	struct rc_addrlist *rcl_top = NULL, *rcl;
  	struct sockaddr *sa;
--- 985,991 ----
  {
  	char rbuf[512];
  	char wbuf[512];
! 	int r;
  	int s = -1;
  	struct rc_addrlist *rcl_top = NULL, *rcl;
  	struct sockaddr *sa;
***************
*** 1111,1118 ****
  		fprintf(stdout, "hash=%s\n", cid.hash);
  	}
  
! 	snprintf(wbuf, sizeof(wbuf), "LOGIN %s\r\n", cid.hash);
! 	w = sc_writemsg(s, wbuf, strlen(wbuf));
  	r = sc_getline(s, rbuf, sizeof(rbuf));
  	if (r<0) {
  		perror("LOGIN:read");
--- 1119,1126 ----
  		fprintf(stdout, "hash=%s\n", cid.hash);
  	}
  
! 	if (sc_writestr(s, "LOGIN %s\r\n", cid.hash) < 0)
! 		exit(EXIT_FAILURE);
  	r = sc_getline(s, rbuf, sizeof(rbuf));
  	if (r<0) {
  		perror("LOGIN:read");
***************
*** 1134,1142 ****
  sc_quit(int s)
  {
  	char rbuf[512];
! 	int r,w;
  
! 	w = sc_writemsg(s, "QUIT\r\n", strlen("QUIT\r\n"));
  	r = sc_getline(s, rbuf, sizeof(rbuf));
  	if (r<0) {
  		perror("QUIT:read");
--- 1142,1153 ----
  sc_quit(int s)
  {
  	char rbuf[512];
! 	int r;
  
! 	if (sc_writestr(s, "QUIT\r\n")) {
! 		close(s);
! 		return -1;
! 	}
  	r = sc_getline(s, rbuf, sizeof(rbuf));
  	if (r<0) {
  		perror("QUIT:read");
