// $NetBSD: netbsd.c,v 1.1.1.1 2013/03/17 14:12:02 asau Exp $

// Add necessary functions not provided by NetBSD's NSS

#include <sys/param.h>
#include <pwd.h>
#include <grp.h>
#include <nsswitch.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "netbsd.h"
typedef enum nss_status NSS_STATUS;

extern NSS_STATUS _nss_pgsql_setpwent(void);
static int netbsd_setpwent(void *, void *, va_list);
static int netbsd_setpassent(void *, void *, va_list);
extern NSS_STATUS _nss_pgsql_endpwent(void);
static int netbsd_endpwent(void *, void *, va_list);
extern NSS_STATUS _nss_pgsql_getpwent_r(struct passwd *,
				       char *, size_t, int *);
static int netbsd_getpwent(void *, void *, va_list);
static int netbsd_getpwent_r(void *, void *, va_list);
extern NSS_STATUS _nss_pgsql_getpwnam_r(const char *, struct passwd *,
				       char *, size_t, int *);
static int netbsd_getpwnam(void *, void *, va_list);
static int netbsd_getpwnam_r(void *, void *, va_list);
extern NSS_STATUS _nss_pgsql_getpwuid_r(uid_t, struct passwd *,
				       char *, size_t, int *);
static int netbsd_getpwuid(void *, void *, va_list);
static int netbsd_getpwuid_r(void *, void *, va_list);

extern NSS_STATUS _nss_pgsql_setgrent(void);
static int netbsd_setgrent(void *, void *, va_list);
static int netbsd_setgroupent(void *, void *, va_list);
extern NSS_STATUS _nss_pgsql_endgrent(void);
static int netbsd_endgrent(void *, void *, va_list);
extern NSS_STATUS _nss_pgsql_getgrent_r(struct group *,
				       char *, size_t, int *);
static int netbsd_getgrent(void *, void *, va_list);
static int netbsd_getgrent_r(void *, void *, va_list);
extern NSS_STATUS _nss_pgsql_getgrnam_r(const char *, struct group *,
				       char *, size_t, int *);
static int netbsd_getgrnam(void *, void *, va_list);
static int netbsd_getgrnam_r(void *, void *, va_list);
extern NSS_STATUS _nss_pgsql_getgrgid_r(gid_t, struct group *,
				       char *, size_t, int *);
static int netbsd_getgrgid(void *, void *, va_list);
static int netbsd_getgrgid_r(void *, void *, va_list);
extern NSS_STATUS _nss_pgsql_initgroups_dyn(const char *, gid_t, long int *,
	long int *, gid_t **, long int, int *);
static int netbsd_getgroupmembership(void *, void *, va_list);

static int nss2netbsderr[] = {
	NS_SUCCESS, NS_NOTFOUND, NS_UNAVAIL, NS_TRYAGAIN, NS_RETURN
};
static struct passwd rpw;
static struct group rg;
static char pwbuf[1024];
static char *grpbuf;
static size_t grpbuflen;

static ns_mtab methods[] = {
	{ NSDB_PASSWD, "setpwent", netbsd_setpwent, 0 },
	{ NSDB_PASSWD, "setpassent", netbsd_setpassent, 0 },
	{ NSDB_PASSWD, "endpwent", netbsd_endpwent, 0 },
	{ NSDB_PASSWD, "getpwent", netbsd_getpwent, 0 },
	{ NSDB_PASSWD, "getpwent_r", netbsd_getpwent_r, 0 },
	{ NSDB_PASSWD, "getpwnam", netbsd_getpwnam, 0 },
	{ NSDB_PASSWD, "getpwnam_r", netbsd_getpwnam_r, 0 },
	{ NSDB_PASSWD, "getpwuid", netbsd_getpwuid, 0 },
	{ NSDB_PASSWD, "getpwuid_r", netbsd_getpwuid_r, 0 },

	{ NSDB_GROUP, "setgrent", netbsd_setgrent, 0 },
	{ NSDB_GROUP, "setgroupent", netbsd_setgroupent, 0 },
	{ NSDB_GROUP, "endgrent", netbsd_endgrent, 0 },
	{ NSDB_GROUP, "getgrent", netbsd_getgrent, 0 },
	{ NSDB_GROUP, "getgrent_r", netbsd_getgrent_r, 0 },
	{ NSDB_GROUP, "getgrnam", netbsd_getgrnam, 0 },
	{ NSDB_GROUP, "getgrnam_r", netbsd_getgrnam_r, 0 },
	{ NSDB_GROUP, "getgrgid", netbsd_getgrgid, 0 },
	{ NSDB_GROUP, "getgrgid_r", netbsd_getgrgid_r, 0 },
	{ NSDB_GROUP, "getgroupmembership", netbsd_getgroupmembership, 0 },
};

static int
netbsd_setpwent(void *rv, void *cb_data, va_list ap)
{
	NSS_STATUS s;

	s = _nss_pgsql_setpwent();

	return nss2netbsderr[s];
}

static int
netbsd_setpassent(void *rv, void *cb_data, va_list ap)
{
	NSS_STATUS s;
	int *retval = va_arg(ap, int *);
	int stayopen = va_arg(ap, int);

	/* XXX stayopen ignored */
	s = _nss_pgsql_setpwent();

	if (s == NSS_STATUS_SUCCESS)
		*retval = 1;
	else
		*retval = 0;

	return nss2netbsderr[s];
}

static int
netbsd_endpwent(void *rv, void *cb_data, va_list ap)
{
	NSS_STATUS s;

	s = _nss_pgsql_endpwent();

	return nss2netbsderr[s];
}

static int
netbsd_getpwent(void *rv, void *cb_data, va_list ap)
{
	int err;
	NSS_STATUS s;
	struct passwd **retval = va_arg(ap, struct passwd **);

	memset(&rpw, 0, sizeof(rpw));
	s = _nss_pgsql_getpwent_r(&rpw, pwbuf, sizeof(pwbuf), &err);

	if (s == NSS_STATUS_SUCCESS) {
		rpw.pw_class = ""; /* XXX */
		*retval = &rpw;
	} else
		*retval = 0;

	return nss2netbsderr[s];
}

static int
netbsd_getpwent_r(void *rv, void *cb_data, va_list ap)
{
	int err;
	NSS_STATUS s;
	int *retval = va_arg(ap, int *);
	struct passwd *pw = va_arg(ap, struct passwd *);
	char *buf = va_arg(ap, char *);
	size_t buflen = va_arg(ap, size_t);
	struct passwd **result = va_arg(ap, struct passwd **);

	memset(pw, 0, sizeof(*pw));
	s = _nss_pgsql_getpwent_r(pw, buf, buflen, &err);

	if (s == NSS_STATUS_SUCCESS) {
		pw->pw_class = ""; /* XXX */
		*result = pw;
	} else
		*result = 0;

	if (s == NSS_STATUS_SUCCESS || s == NSS_STATUS_NOTFOUND)
		*retval = 0;
	else
		*retval = 1;

	return nss2netbsderr[s];
}

static int
netbsd_getpwnam(void *rv, void *cb_data, va_list ap)
{
	int err;
	NSS_STATUS s;
	struct passwd **retval = va_arg(ap, struct passwd **);
	const char *name = va_arg(ap, const char *);

	memset(&rpw, 0, sizeof(rpw));
	s = _nss_pgsql_getpwnam_r(name, &rpw, pwbuf, sizeof(pwbuf), &err);

	if (s == NSS_STATUS_SUCCESS) {
		rpw.pw_class = ""; /* XXX */
		*retval = &rpw;
	} else
		*retval = 0;

	return nss2netbsderr[s];
}

static int
netbsd_getpwnam_r(void *rv, void *cb_data, va_list ap)
{
	int err;
	NSS_STATUS s;
	int *retval = va_arg(ap, int *);
	const char *name = va_arg(ap, const char *);
	struct passwd *pw = va_arg(ap, struct passwd *);
	char *buf = va_arg(ap, char *);
	size_t buflen = va_arg(ap, size_t);
	struct passwd **result = va_arg(ap, struct passwd **);

	memset(pw, 0, sizeof(*pw));
	s = _nss_pgsql_getpwnam_r(name, pw, buf, buflen, &err);

	if (s == NSS_STATUS_SUCCESS) {
		pw->pw_class = ""; /* XXX */
		*result = pw;
	} else
		*result = 0;

	if (s == NSS_STATUS_SUCCESS || s == NSS_STATUS_NOTFOUND)
		*retval = 0;
	else
		*retval = 1;

	return nss2netbsderr[s];
}

static int
netbsd_getpwuid(void *rv, void *cb_data, va_list ap)
{
	int err;
	NSS_STATUS s;
	struct passwd **retval = va_arg(ap, struct passwd **);
	uid_t uid = va_arg(ap, uid_t);

	memset(&rpw, 0, sizeof(rpw));
	s = _nss_pgsql_getpwuid_r(uid, &rpw, pwbuf, sizeof(pwbuf), &err);

	if (s == NSS_STATUS_SUCCESS) {
		rpw.pw_class = ""; /* XXX */
		*retval = &rpw;
	} else
		*retval = 0;

	return nss2netbsderr[s];
}

static int
netbsd_getpwuid_r(void *rv, void *cb_data, va_list ap)
{
	int err;
	NSS_STATUS s;
	int *retval = va_arg(ap, int *);
	uid_t uid = va_arg(ap, uid_t);
	struct passwd *pw = va_arg(ap, struct passwd *);
	char *buf = va_arg(ap, char *);
	size_t buflen = va_arg(ap, size_t);
	struct passwd **result = va_arg(ap, struct passwd **);

	memset(pw, 0, sizeof(*pw));
	s = _nss_pgsql_getpwuid_r(uid, pw, buf, buflen, &err);

	if (s == NSS_STATUS_SUCCESS) {
		pw->pw_class = ""; /* XXX */
		*result = pw;
	} else
		*result = 0;

	if (s == NSS_STATUS_SUCCESS || s == NSS_STATUS_NOTFOUND)
		*retval = 0;
	else
		*retval = 1;

	return nss2netbsderr[s];
}

static int
resize_grpbuf()
{

	if (grpbuflen > 50000) /* safety guard */
		return (-1);
	grpbuflen += 1024;
	if (grpbuf)
		free(grpbuf);
	grpbuf = malloc(grpbuflen);
	if (!grpbuf)
		return (-1);
	return (0);
}

static int
netbsd_setgrent(void *rv, void *cb_data, va_list ap)
{
	NSS_STATUS s;

	s = _nss_pgsql_setgrent();

	return nss2netbsderr[s];
}

static int
netbsd_setgroupent(void *rv, void *cb_data, va_list ap)
{
	NSS_STATUS s;
	int *retval = va_arg(ap, int *);
	int stayopen = va_arg(ap, int);

	/* XXX stayopen ignored */
	s = _nss_pgsql_setgrent();

	if (s == NSS_STATUS_SUCCESS)
		*retval = 1;
	else
		*retval = 0;

	return nss2netbsderr[s];
}

static int
netbsd_endgrent(void *rv, void *cb_data, va_list ap)
{
	NSS_STATUS s;

	s = _nss_pgsql_endgrent();

	return nss2netbsderr[s];
}

static int
netbsd_getgrent(void *rv, void *cb_data, va_list ap)
{
	int err;
	NSS_STATUS s;
	struct group **retval = va_arg(ap, struct group **);

tryagain:
	memset(&rg, 0, sizeof(rg));
	s = _nss_pgsql_getgrent_r(&rg, grpbuf, grpbuflen, &err);

	if (s == NSS_STATUS_SUCCESS)
		*retval = &rg;
	else if ((s == NSS_STATUS_TRYAGAIN) && (err == ERANGE)
		 && (resize_grpbuf() == 0))
		goto tryagain;
	else
		*retval = 0;

	return nss2netbsderr[s];
}

static int
netbsd_getgrent_r(void *rv, void *cb_data, va_list ap)
{
	int err;
	NSS_STATUS s;
	int *retval = va_arg(ap, int *);
	struct group *grp = va_arg(ap, struct group *);
	char *buf = va_arg(ap, char *);
	size_t buflen = va_arg(ap, size_t);
	struct group **result = va_arg(ap, struct group **);

	memset(grp, 0, sizeof(*grp));
	s = _nss_pgsql_getgrent_r(grp, buf, buflen, &err);

	if (s == NSS_STATUS_SUCCESS)
		*result = grp;
	else
		*result = 0;

	if (s == NSS_STATUS_SUCCESS || s == NSS_STATUS_NOTFOUND)
		*retval = 0;
	else
		*retval = 1;

	return nss2netbsderr[s];
}

static int
netbsd_getgrnam(void *rv, void *cb_data, va_list ap)
{
	int err;
	NSS_STATUS s;
	struct group **retval = va_arg(ap, struct group **);
	const char *name = va_arg(ap, const char *);

tryagain:
	memset(&rg, 0, sizeof(rg));
	s = _nss_pgsql_getgrnam_r(name, &rg, grpbuf, grpbuflen, &err);

	if (s == NSS_STATUS_SUCCESS)
		*retval = &rg;
	else if ((s == NSS_STATUS_TRYAGAIN) && (err == ERANGE)
		 && (resize_grpbuf() == 0))
		goto tryagain;
	else
		*retval = 0;

	return nss2netbsderr[s];
}

static int
netbsd_getgrnam_r(void *rv, void *cb_data, va_list ap)
{
	int err;
	NSS_STATUS s;
	int *retval = va_arg(ap, int *);
	const char *name = va_arg(ap, const char *);
	struct group *grp = va_arg(ap, struct group *);
	char *buf = va_arg(ap, char *);
	size_t buflen = va_arg(ap, size_t);
	struct group **result = va_arg(ap, struct group **);

	memset(grp, 0, sizeof(*grp));
	s = _nss_pgsql_getgrnam_r(name, grp, buf, buflen, &err);

	if (s == NSS_STATUS_SUCCESS)
		*result = grp;
	else
		*result = 0;

	if (s == NSS_STATUS_SUCCESS || s == NSS_STATUS_NOTFOUND)
		*retval = 0;
	else
		*retval = 1;

	return nss2netbsderr[s];
}

static int
netbsd_getgrgid(void *rv, void *cb_data, va_list ap)
{
	int err;
	NSS_STATUS s;
	struct group **retval = va_arg(ap, struct group **);
	gid_t gid = va_arg(ap, gid_t);

tryagain:
	memset(&rg, 0, sizeof(rg));
	s = _nss_pgsql_getgrgid_r(gid, &rg, grpbuf, grpbuflen, &err);

	if (s == NSS_STATUS_SUCCESS)
		*retval = &rg;
	else if ((s == NSS_STATUS_TRYAGAIN) && (err == ERANGE)
		 && (resize_grpbuf() == 0))
		goto tryagain;
	else
		*retval = 0;

	return nss2netbsderr[s];
}

static int
netbsd_getgrgid_r(void *rv, void *cb_data, va_list ap)
{
	int err;
	NSS_STATUS s;
	int *retval = va_arg(ap, int *);
	gid_t gid = va_arg(ap, gid_t);
	struct group *grp = va_arg(ap, struct group *);
	char *buf = va_arg(ap, char *);
	size_t buflen = va_arg(ap, size_t);
	struct group **result = va_arg(ap, struct group **);

	memset(grp, 0, sizeof(*grp));
	s = _nss_pgsql_getgrgid_r(gid, grp, buf, buflen, &err);

	if (s == NSS_STATUS_SUCCESS)
		*result = grp;
	else
		*result = 0;

	if (s == NSS_STATUS_SUCCESS || s == NSS_STATUS_NOTFOUND)
		*retval = 0;
	else
		*retval = 1;

	return nss2netbsderr[s];
}

/* addgid helper from NetBSD's getgroupmembership.c */
static int
__gr_addgid(gid_t gid, gid_t *groups, int maxgrp, int *groupc)
{
	int	ret, dupc;

						/* skip duplicates */
	for (dupc = 0; dupc < MIN(maxgrp, *groupc); dupc++) {
		if (groups[dupc] == gid)
			return 1;
	}

	ret = 1;
	if (*groupc < maxgrp)			/* add this gid */
		groups[*groupc] = gid;
	else
		ret = 0;
	(*groupc)++;
	return ret;
}


static int
netbsd_getgroupmembership(void *rv, void *cb_data, va_list ap)
{
	int err;
	NSS_STATUS s;
	int *retval = va_arg(ap, int *);
	const char *user = va_arg(ap, const char *);
	gid_t group = va_arg(ap, gid_t);
	gid_t *groups = va_arg(ap, gid_t *);
	int limit = va_arg(ap, int);
	int *size = va_arg(ap, int*);
	gid_t *tmpgroups;
	long int lstart, lsize;
	int i;

	tmpgroups = malloc(limit * sizeof(gid_t));
	if (!tmpgroups)
		return NS_TRYAGAIN;
	/* insert primary membership */
	__gr_addgid(group, groups, limit, size);

	lstart = 0;
	lsize = limit;
	s = _nss_pgsql_initgroups_dyn(user, group, &lstart, &lsize,
		&tmpgroups, 0, &err);
	if (s == NSS_STATUS_SUCCESS) {
		for (i = 0; i < lstart; i++)
			if (! __gr_addgid(tmpgroups[i], groups, limit, size))
				*retval = -1;
		s = NSS_STATUS_NOTFOUND;
	}
	free(tmpgroups);
		
	return nss2netbsderr[s];
}

ns_mtab *
nss_module_register(const char *source, unsigned int *mtabsize,
		    nss_module_unregister_fn *unreg)
{
	*mtabsize = sizeof(methods)/sizeof(methods[0]);
	*unreg = NULL;

	if (resize_grpbuf())
		return 0;

	return (methods);
}
