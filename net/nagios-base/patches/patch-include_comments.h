$NetBSD: patch-include_comments.h,v 1.1 2015/04/12 23:33:06 rodent Exp $

Fix build in SunOS.

--- include/comments.h.orig	2014-08-12 15:00:01.000000000 +0000
+++ include/comments.h
@@ -58,7 +58,7 @@
 NAGIOS_BEGIN_DECL
 
 /* COMMENT structure */
-typedef struct comment {
+typedef struct my_comment {
 	int 	comment_type;
 	int     entry_type;
 	unsigned long comment_id;
@@ -71,11 +71,11 @@ typedef struct comment {
 	char 	*service_description;
 	char 	*author;
 	char 	*comment_data;
-	struct 	comment *next;
-	struct 	comment *nexthash;
-	} comment;
+	struct 	my_comment *next;
+	struct 	my_comment *nexthash;
+	} my_comment;
 
-extern struct comment *comment_list;
+extern struct my_comment *comment_list;
 
 #ifndef NSCGI
 int initialize_comment_data(void);                                /* initializes comment data */
@@ -94,12 +94,12 @@ int delete_service_acknowledgement_comme
 int check_for_expired_comment(unsigned long);                       /* expires a comment */
 #endif
 
-struct comment *find_comment(unsigned long, int);                            /* finds a specific comment */
-struct comment *find_service_comment(unsigned long);                         /* finds a specific service comment */
-struct comment *find_host_comment(unsigned long);                            /* finds a specific host comment */
+struct my_comment *find_comment(unsigned long, int);                            /* finds a specific comment */
+struct my_comment *find_service_comment(unsigned long);                         /* finds a specific service comment */
+struct my_comment *find_host_comment(unsigned long);                            /* finds a specific host comment */
 
-struct comment *get_first_comment_by_host(char *);
-struct comment *get_next_comment_by_host(char *, struct comment *);
+struct my_comment *get_first_comment_by_host(char *);
+struct my_comment *get_next_comment_by_host(char *, struct my_comment *);
 
 int number_of_host_comments(char *);			              /* returns the number of comments associated with a particular host */
 int number_of_service_comments(char *, char *);		              /* returns the number of comments associated with a particular service */
@@ -109,7 +109,7 @@ int sort_comments(void);
 int add_host_comment(int, char *, time_t, char *, char *, unsigned long, int, int, time_t, int);   /* adds a host comment */
 int add_service_comment(int, char *, char *, time_t, char *, char *, unsigned long, int, int, time_t, int); /* adds a service comment */
 
-int add_comment_to_hashlist(struct comment *);
+int add_comment_to_hashlist(struct my_comment *);
 
 void free_comment_data(void);                                             /* frees memory allocated to the comment list */
 
