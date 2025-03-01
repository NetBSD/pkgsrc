$NetBSD: patch-prism_prism.c,v 1.1 2025/03/01 15:56:52 taca Exp $

Avoid use the same name as standard library.

--- prism/prism.c.orig	2025-02-14 21:25:54.000000000 +0000
+++ prism/prism.c
@@ -22615,11 +22615,11 @@ pm_parse(pm_parser_t *parser) {
  * otherwise return true.
  */
 static bool
-pm_parse_stream_read(pm_buffer_t *buffer, void *stream, pm_parse_stream_fgets_t *fgets) {
+pm_parse_stream_read(pm_buffer_t *buffer, void *stream, pm_parse_stream_fgets_t *pm_stream_fgets) {
 #define LINE_SIZE 4096
     char line[LINE_SIZE];
 
-    while (memset(line, '\n', LINE_SIZE), fgets(line, LINE_SIZE, stream) != NULL) {
+    while (memset(line, '\n', LINE_SIZE), pm_stream_fgets(line, LINE_SIZE, stream) != NULL) {
         size_t length = LINE_SIZE;
         while (length > 0 && line[length - 1] == '\n') length--;
 
@@ -22686,16 +22686,16 @@ pm_parse_stream_unterminated_heredoc_p(p
  * can stream stdin in to Ruby so we need to support a streaming API.
  */
 PRISM_EXPORTED_FUNCTION pm_node_t *
-pm_parse_stream(pm_parser_t *parser, pm_buffer_t *buffer, void *stream, pm_parse_stream_fgets_t *fgets, const pm_options_t *options) {
+pm_parse_stream(pm_parser_t *parser, pm_buffer_t *buffer, void *stream, pm_parse_stream_fgets_t *pm_stream_fgets, const pm_options_t *options) {
     pm_buffer_init(buffer);
 
-    bool eof = pm_parse_stream_read(buffer, stream, fgets);
+    bool eof = pm_parse_stream_read(buffer, stream, pm_stream_fgets);
     pm_parser_init(parser, (const uint8_t *) pm_buffer_value(buffer), pm_buffer_length(buffer), options);
     pm_node_t *node = pm_parse(parser);
 
     while (!eof && parser->error_list.size > 0 && (parser->lex_modes.index > 0 || pm_parse_stream_unterminated_heredoc_p(parser))) {
         pm_node_destroy(parser, node);
-        eof = pm_parse_stream_read(buffer, stream, fgets);
+        eof = pm_parse_stream_read(buffer, stream, pm_stream_fgets);
 
         pm_parser_free(parser);
         pm_parser_init(parser, (const uint8_t *) pm_buffer_value(buffer), pm_buffer_length(buffer), options);
@@ -22787,13 +22787,13 @@ pm_serialize_parse(pm_buffer_t *buffer, 
  * given stream into to the given buffer.
  */
 PRISM_EXPORTED_FUNCTION void
-pm_serialize_parse_stream(pm_buffer_t *buffer, void *stream, pm_parse_stream_fgets_t *fgets, const char *data) {
+pm_serialize_parse_stream(pm_buffer_t *buffer, void *stream, pm_parse_stream_fgets_t *pm_stream_fgets, const char *data) {
     pm_parser_t parser;
     pm_options_t options = { 0 };
     pm_options_read(&options, data);
 
     pm_buffer_t parser_buffer;
-    pm_node_t *node = pm_parse_stream(&parser, &parser_buffer, stream, fgets, &options);
+    pm_node_t *node = pm_parse_stream(&parser, &parser_buffer, stream, pm_stream_fgets, &options);
     pm_serialize_header(buffer);
     pm_serialize_content(&parser, node, buffer);
     pm_buffer_append_byte(buffer, '\0');
