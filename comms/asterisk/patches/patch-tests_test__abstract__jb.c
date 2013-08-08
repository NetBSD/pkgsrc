$NetBSD: patch-tests_test__abstract__jb.c,v 1.1 2013/08/08 00:45:10 jnemeth Exp $

--- tests/test_abstract_jb.c.orig	2012-07-23 21:15:26.000000000 +0000
+++ tests/test_abstract_jb.c
@@ -177,8 +177,11 @@ static struct ast_jb default_jb = {
  * \param type_name The enum type of the jitter buffer to create
  * \param literal_type_name The literal name of the type - "fixed" or "adaptive"
  */
+
+RAII_DECL(struct ast_jb *, jb, dispose_jitterbuffer);
+
 #define test_create_nominal(type_name, literal_type_name) AST_TEST_DEFINE(TEST_NAME(type_name, create)) {\
-	RAII_VAR(struct ast_jb *, jb, &default_jb, dispose_jitterbuffer); \
+	RAII_VAR(struct ast_jb *, jb, &default_jb); \
 	const struct ast_jb_impl *impl; \
 	struct ast_jb_conf conf; \
 \
@@ -213,12 +216,16 @@ static struct ast_jb default_jb = {
  * \param type_name The enum type of the jitter buffer to create
  * \param literal_type_name The literal name of the type - "fixed" or "adaptive"
  */
+
+RAII_DECL(struct ast_frame *, expected_frame, dispose_frame);
+RAII_DECL(struct ast_frame *, actual_frame, dispose_frame);
+
 #define test_put_first(type_name, literal_type_name) AST_TEST_DEFINE(TEST_NAME(type_name,  put_first)) {\
-	RAII_VAR(struct ast_jb *, jb, &default_jb, dispose_jitterbuffer); \
+	RAII_VAR(struct ast_jb *, jb, &default_jb); \
 	const struct ast_jb_impl *impl; \
 	struct ast_jb_conf conf; \
-	RAII_VAR(struct ast_frame *, expected_frame, NULL, dispose_frame); \
-	RAII_VAR(struct ast_frame *, actual_frame, NULL, dispose_frame); \
+	RAII_VAR(struct ast_frame *, expected_frame, NULL); \
+	RAII_VAR(struct ast_frame *, actual_frame, NULL); \
 	int res; \
 \
 	switch (cmd) { \
@@ -270,11 +277,11 @@ static struct ast_jb default_jb = {
  * \param literal_type_name The literal name of the type - "fixed" or "adaptive"
  */
 #define test_put(type_name, literal_type_name) AST_TEST_DEFINE(TEST_NAME(type_name, put)) {\
-	RAII_VAR(struct ast_jb *, jb, &default_jb, dispose_jitterbuffer); \
+	RAII_VAR(struct ast_jb *, jb, &default_jb); \
 	const struct ast_jb_impl *impl; \
 	struct ast_jb_conf conf; \
-	RAII_VAR(struct ast_frame *, expected_frame, NULL, dispose_frame); \
-	RAII_VAR(struct ast_frame *, actual_frame, NULL, dispose_frame); \
+	RAII_VAR(struct ast_frame *, expected_frame, NULL); \
+	RAII_VAR(struct ast_frame *, actual_frame, NULL); \
 	int res; \
 	long next; \
 	int i; \
@@ -333,10 +340,10 @@ static struct ast_jb default_jb = {
  * \param overflow_limit The number of frames at which we expect the buffer to overflow
  */
 #define test_put_overflow(type_name, literal_type_name, overflow_limit) AST_TEST_DEFINE(TEST_NAME(type_name, put_overflow)) {\
-	RAII_VAR(struct ast_jb *, jb, &default_jb, dispose_jitterbuffer); \
+	RAII_VAR(struct ast_jb *, jb, &default_jb); \
 	const struct ast_jb_impl *impl; \
 	struct ast_jb_conf conf; \
-	RAII_VAR(struct ast_frame *, expected_frame, NULL, dispose_frame); \
+	RAII_VAR(struct ast_frame *, expected_frame, NULL); \
 	int res; \
 	int i; \
 \
@@ -398,11 +405,11 @@ static struct ast_jb default_jb = {
  * \param synch_limit The synchronization limit for this particular type of jitter buffer
  */
 #define test_put_out_of_order(type_name, literal_type_name, synch_limit) AST_TEST_DEFINE(TEST_NAME(type_name, put_out_of_order)) {\
-	RAII_VAR(struct ast_jb *, jb, &default_jb, dispose_jitterbuffer); \
+	RAII_VAR(struct ast_jb *, jb, &default_jb); \
 	const struct ast_jb_impl *impl; \
 	struct ast_jb_conf conf; \
-	RAII_VAR(struct ast_frame *, actual_frame, NULL, dispose_frame); \
-	RAII_VAR(struct ast_frame *, expected_frame, NULL, dispose_frame); \
+	RAII_VAR(struct ast_frame *, actual_frame, NULL); \
+	RAII_VAR(struct ast_frame *, expected_frame, NULL); \
 	int res; \
 	long next; \
 	int i; \
