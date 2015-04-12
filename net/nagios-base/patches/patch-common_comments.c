$NetBSD: patch-common_comments.c,v 1.1 2015/04/12 23:33:06 rodent Exp $

Fix build in SunOS.

--- common/comments.c.orig	2014-08-12 15:00:01.000000000 +0000
+++ common/comments.c
@@ -36,9 +36,9 @@
 #endif
 
 
-comment     *comment_list = NULL;
+my_comment     *comment_list = NULL;
 int	    defer_comment_sorting = 0;
-comment     **comment_hashlist = NULL;
+my_comment     **comment_hashlist = NULL;
 
 
 
@@ -131,12 +131,12 @@ int add_new_service_comment(int entry_ty
 
 /* deletes a host or service comment */
 int delete_comment(int type, unsigned long comment_id) {
-	comment *this_comment = NULL;
-	comment *last_comment = NULL;
-	comment *next_comment = NULL;
+	my_comment *this_comment = NULL;
+	my_comment *last_comment = NULL;
+	my_comment *next_comment = NULL;
 	int hashslot = 0;
-	comment *this_hash = NULL;
-	comment *last_hash = NULL;
+	my_comment *this_hash = NULL;
+	my_comment *last_hash = NULL;
 
 	/* find the comment we should remove */
 	for(this_comment = comment_list, last_comment = comment_list; this_comment != NULL; this_comment = next_comment) {
@@ -232,8 +232,8 @@ int delete_all_comments(int type, char *
 /* deletes all comments for a particular host */
 int delete_all_host_comments(char *host_name) {
 	int result = OK;
-	comment *temp_comment = NULL;
-	comment *next_comment = NULL;
+	my_comment *temp_comment = NULL;
+	my_comment *next_comment = NULL;
 
 	if(host_name == NULL)
 		return ERROR;
@@ -252,8 +252,8 @@ int delete_all_host_comments(char *host_
 /* deletes all non-persistent acknowledgement comments for a particular host */
 int delete_host_acknowledgement_comments(host *hst) {
 	int result = OK;
-	comment *temp_comment = NULL;
-	comment *next_comment = NULL;
+	my_comment *temp_comment = NULL;
+	my_comment *next_comment = NULL;
 
 	if(hst == NULL)
 		return ERROR;
@@ -275,8 +275,8 @@ int delete_host_acknowledgement_comments
 /* deletes all comments for a particular service */
 int delete_all_service_comments(char *host_name, char *svc_description) {
 	int result = OK;
-	comment *temp_comment = NULL;
-	comment *next_comment = NULL;
+	my_comment *temp_comment = NULL;
+	my_comment *next_comment = NULL;
 
 	if(host_name == NULL || svc_description == NULL)
 		return ERROR;
@@ -295,8 +295,8 @@ int delete_all_service_comments(char *ho
 /* deletes all non-persistent acknowledgement comments for a particular service */
 int delete_service_acknowledgement_comments(service *svc) {
 	int result = OK;
-	comment *temp_comment = NULL;
-	comment *next_comment = NULL;
+	my_comment *temp_comment = NULL;
+	my_comment *next_comment = NULL;
 
 	if(svc == NULL)
 		return ERROR;
@@ -314,7 +314,7 @@ int delete_service_acknowledgement_comme
 
 /* checks for an expired comment (and removes it) */
 int check_for_expired_comment(unsigned long comment_id) {
-	comment *temp_comment = NULL;
+	my_comment *temp_comment = NULL;
 
 	/* check all comments */
 	for(temp_comment = comment_list; temp_comment != NULL; temp_comment = temp_comment->next) {
@@ -341,16 +341,16 @@ int check_for_expired_comment(unsigned l
 /******************************************************************/
 
 /* adds comment to hash list in memory */
-int add_comment_to_hashlist(comment *new_comment) {
-	comment *temp_comment = NULL;
-	comment *lastpointer = NULL;
+int add_comment_to_hashlist(my_comment *new_comment) {
+	my_comment *temp_comment = NULL;
+	my_comment *lastpointer = NULL;
 	int hashslot = 0;
 
 	/* initialize hash list */
 	if(comment_hashlist == NULL) {
 		int i;
 
-		comment_hashlist = (comment **)malloc(sizeof(comment *) * COMMENT_HASHSLOTS);
+		comment_hashlist = (my_comment **)malloc(sizeof(my_comment *) * COMMENT_HASHSLOTS);
 		if(comment_hashlist == NULL)
 			return 0;
 
@@ -410,9 +410,9 @@ int add_service_comment(int entry_type, 
 
 /* adds a comment to the list in memory */
 int add_comment(int comment_type, int entry_type, char *host_name, char *svc_description, time_t entry_time, char *author, char *comment_data, unsigned long comment_id, int persistent, int expires, time_t expire_time, int source) {
-	comment *new_comment = NULL;
-	comment *last_comment = NULL;
-	comment *temp_comment = NULL;
+	my_comment *new_comment = NULL;
+	my_comment *last_comment = NULL;
+	my_comment *temp_comment = NULL;
 	int result = OK;
 
 	/* make sure we have the data we need */
@@ -420,7 +420,7 @@ int add_comment(int comment_type, int en
 		return ERROR;
 
 	/* allocate memory for the comment */
-	if((new_comment = (comment *)calloc(1, sizeof(comment))) == NULL)
+	if((new_comment = (my_comment *)calloc(1, sizeof(my_comment))) == NULL)
 		return ERROR;
 
 	/* duplicate vars */
@@ -500,13 +500,13 @@ int add_comment(int comment_type, int en
 	}
 
 static int comment_compar(const void *p1, const void *p2) {
-	comment *c1 = *(comment **)p1;
-	comment *c2 = *(comment **)p2;
+	my_comment *c1 = *(my_comment **)p1;
+	my_comment *c2 = *(my_comment **)p2;
 	return c1->comment_id - c2->comment_id;
 	}
 
 int sort_comments(void) {
-	comment **array, *temp_comment;
+	my_comment **array, *temp_comment;
 	unsigned long i = 0, unsorted_comments = 0;
 
 	if(!defer_comment_sorting)
@@ -546,8 +546,8 @@ int sort_comments(void) {
 
 /* frees memory allocated for the comment data */
 void free_comment_data(void) {
-	comment *this_comment = NULL;
-	comment *next_comment = NULL;
+	my_comment *this_comment = NULL;
+	my_comment *next_comment = NULL;
 
 	/* free memory for the comment list */
 	for(this_comment = comment_list; this_comment != NULL; this_comment = next_comment) {
@@ -576,7 +576,7 @@ void free_comment_data(void) {
 
 /* get the number of comments associated with a particular host */
 int number_of_host_comments(char *host_name) {
-	comment *temp_comment = NULL;
+	my_comment *temp_comment = NULL;
 	int total_comments = 0;
 
 	if(host_name == NULL)
@@ -593,7 +593,7 @@ int number_of_host_comments(char *host_n
 
 /* get the number of comments associated with a particular service */
 int number_of_service_comments(char *host_name, char *svc_description) {
-	comment *temp_comment = NULL;
+	my_comment *temp_comment = NULL;
 	int total_comments = 0;
 
 	if(host_name == NULL || svc_description == NULL)
@@ -613,14 +613,14 @@ int number_of_service_comments(char *hos
 /********************* TRAVERSAL FUNCTIONS ************************/
 /******************************************************************/
 
-comment *get_first_comment_by_host(char *host_name) {
+my_comment *get_first_comment_by_host(char *host_name) {
 
 	return get_next_comment_by_host(host_name, NULL);
 	}
 
 
-comment *get_next_comment_by_host(char *host_name, comment *start) {
-	comment *temp_comment = NULL;
+my_comment *get_next_comment_by_host(char *host_name, my_comment *start) {
+	my_comment *temp_comment = NULL;
 
 	if(host_name == NULL || comment_hashlist == NULL)
 		return NULL;
@@ -645,22 +645,22 @@ comment *get_next_comment_by_host(char *
 /******************************************************************/
 
 /* find a service comment by id */
-comment *find_service_comment(unsigned long comment_id) {
+my_comment *find_service_comment(unsigned long comment_id) {
 
 	return find_comment(comment_id, SERVICE_COMMENT);
 	}
 
 
 /* find a host comment by id */
-comment *find_host_comment(unsigned long comment_id) {
+my_comment *find_host_comment(unsigned long comment_id) {
 
 	return find_comment(comment_id, HOST_COMMENT);
 	}
 
 
 /* find a comment by id */
-comment *find_comment(unsigned long comment_id, int comment_type) {
-	comment *temp_comment = NULL;
+my_comment *find_comment(unsigned long comment_id, int comment_type) {
+	my_comment *temp_comment = NULL;
 
 	for(temp_comment = comment_list; temp_comment != NULL; temp_comment = temp_comment->next) {
 		if(temp_comment->comment_id == comment_id && temp_comment->comment_type == comment_type)
