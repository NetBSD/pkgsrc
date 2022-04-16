$NetBSD: patch-lib_functions.php,v 1.5 2022/04/16 03:11:28 khorben Exp $

Fix for PHP 5.5 and later: 
	https://bugzilla.redhat.com/show_bug.cgi?id=974928

--- lib/functions.php.orig	2022-04-15 22:45:43.000000000 +0000
+++ lib/functions.php
@@ -130,12 +130,13 @@ function app_error_handler($errno,$errst
 		debug_log('Entered (%%)',1,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
 	/**
-	 * error_reporting will be 0 if the error context occurred
-	 * within a function call with '@' preprended (ie, @ldap_bind() );
+	 * error_reporting will be only the non-ignorable error number bits
+	 * if the error context occurred within a function call with '@'
+	 * preprended (ie, @ldap_bind() );
 	 * So, don't report errors if the caller has specifically
 	 * disabled them with '@'
 	 */
-	if (ini_get('error_reporting') == 0 || error_reporting() == 0)
+	if (!(ini_get('error_reporting') & error_reporting() & $errno))
 		return;
 
 	$file = basename($file);
@@ -928,7 +929,7 @@ function get_cached_item($index,$item,$s
  *
  * Returns true on success of false on failure.
  */
-function set_cached_item($index,$item,$subitem='null',$data) {
+function set_cached_item($index,$data,$item,$subitem='null') {
 	if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 		debug_log('Entered (%%)',1,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
@@ -2032,8 +2033,8 @@ function ldap_error_msg($msg,$errnum) {
  *
  * Usage Examples:
  *  <code>
- *   draw_jpeg_photo(0,'cn=Bob,ou=People,dc=example,dc=com',"jpegPhoto",0,true,array('img_opts'=>"border: 1px; width: 150px"));
- *   draw_jpeg_photo(1,'cn=Fred,ou=People,dc=example,dc=com',null,1);
+ *   draw_jpeg_photo(0,'cn=Bob,ou=People,dc=example,dc=com',0,"jpegPhoto",true,array('img_opts'=>"border: 1px; width: 150px"));
+ *   draw_jpeg_photo(1,'cn=Fred,ou=People,dc=example,dc=com',1,null);
  *  </code>
  *
  * @param object The Server to get the image from.
@@ -2046,7 +2047,7 @@ function ldap_error_msg($msg,$errnum) {
  * @param array Specifies optional image and CSS style attributes for the table tag. Supported keys are
  *                fixed_width, fixed_height, img_opts.
  */
-function draw_jpeg_photo($server,$dn,$attr_name='jpegphoto',$index,$draw_delete_buttons=false,$options=array()) {
+function draw_jpeg_photo($server,$dn,$index,$attr_name='jpegphoto',$draw_delete_buttons=false,$options=array()) {
 	if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 		debug_log('Entered (%%)',1,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
