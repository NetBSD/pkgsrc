$NetBSD: patch-src_plugins_weechat-plugin.h,v 1.1 2014/11/30 02:10:43 markd Exp $

fix compilation of plugin API functions (macros) when compiler
optimizations are enabled
commit 03c0067272caae88758fd7847689177c0e18b48d

--- src/plugins/weechat-plugin.h.orig	2014-08-15 08:09:01.000000000 +0000
+++ src/plugins/weechat-plugin.h
@@ -950,260 +950,263 @@ extern int weechat_plugin_end (struct t_
 
 /* plugins */
 #define weechat_plugin_get_name(__plugin)                               \
-    weechat_plugin->plugin_get_name(__plugin)
+    (weechat_plugin->plugin_get_name)(__plugin)
 
 /* strings */
 #define weechat_charset_set(__charset)                                  \
-    weechat_plugin->charset_set(weechat_plugin, __charset)
+    (weechat_plugin->charset_set)(weechat_plugin, __charset)
 #define weechat_iconv_to_internal(__charset, __string)                  \
-    weechat_plugin->iconv_to_internal(__charset, __string)
+    (weechat_plugin->iconv_to_internal)(__charset, __string)
 #define weechat_iconv_from_internal(__charset, __string)                \
-    weechat_plugin->iconv_from_internal(__charset, __string)
+    (weechat_plugin->iconv_from_internal)(__charset, __string)
 #ifndef WEECHAT_H
 #ifndef _
-#define _(string) weechat_plugin->gettext(string)
+#define _(string) (weechat_plugin->gettext)(string)
 #endif /* _ */
 #ifndef N_
 #define N_(string) (string)
 #endif /* N_ */
 #ifndef NG_
 #define NG_(single,plural,number)                                       \
-    weechat_plugin->ngettext(single, plural, number)
+    (weechat_plugin->ngettext)(single, plural, number)
 #endif /* NG_ */
 #endif /* WEECHAT_H */
-#define weechat_gettext(string) weechat_plugin->gettext(string)
+#define weechat_gettext(string) (weechat_plugin->gettext)(string)
 #define weechat_ngettext(single,plural,number)                          \
-    weechat_plugin->ngettext(single, plural, number)
+    (weechat_plugin->ngettext)(single, plural, number)
 #define weechat_strndup(__string, __length)                             \
-    weechat_plugin->strndup(__string, __length)
+    (weechat_plugin->strndup)(__string, __length)
 #define weechat_string_tolower(__string)                                \
-    weechat_plugin->string_tolower(__string)
+    (weechat_plugin->string_tolower)(__string)
 #define weechat_string_toupper(__string)                                \
-    weechat_plugin->string_toupper(__string)
+    (weechat_plugin->string_toupper)(__string)
 #define weechat_strcasecmp(__string1, __string2)                        \
-    weechat_plugin->strcasecmp(__string1, __string2)
+    (weechat_plugin->strcasecmp)(__string1, __string2)
 #define weechat_strcasecmp_range(__string1, __string2, __range)         \
-    weechat_plugin->strcasecmp_range(__string1, __string2, __range)
+    (weechat_plugin->strcasecmp_range)(__string1, __string2, __range)
 #define weechat_strncasecmp(__string1, __string2, __max)                \
-    weechat_plugin->strncasecmp(__string1, __string2, __max)
+    (weechat_plugin->strncasecmp)(__string1, __string2, __max)
 #define weechat_strncasecmp_range(__string1, __string2, __max, __range) \
-    weechat_plugin->strncasecmp_range(__string1, __string2, __max,      \
-                                      __range)
+    (weechat_plugin->strncasecmp_range)(__string1, __string2, __max,    \
+                                        __range)
 #define weechat_strcmp_ignore_chars(__string1, __string2,               \
                                     __chars_ignored, __case_sensitive)  \
-    weechat_plugin->strcmp_ignore_chars(__string1, __string2,           \
-                                        __chars_ignored,                \
-                                        __case_sensitive)
+    (weechat_plugin->strcmp_ignore_chars)(__string1, __string2,         \
+                                          __chars_ignored,              \
+                                          __case_sensitive)
 #define weechat_strcasestr(__string, __search)                          \
-    weechat_plugin->strcasestr(__string, __search)
+    (weechat_plugin->strcasestr)(__string, __search)
 #define weechat_strlen_screen(__string)                                 \
-    weechat_plugin->strlen_screen(__string)
+    (weechat_plugin->strlen_screen)(__string)
 #define weechat_string_match(__string, __mask, __case_sensitive)        \
-    weechat_plugin->string_match(__string, __mask, __case_sensitive)
+    (weechat_plugin->string_match)(__string, __mask, __case_sensitive)
 #define weechat_string_replace(__string, __search, __replace)           \
-    weechat_plugin->string_replace(__string, __search, __replace)
-#define weechat_string_expand_home(__path)      \
-    weechat_plugin->string_expand_home(__path)
+    (weechat_plugin->string_replace)(__string, __search, __replace)
+#define weechat_string_expand_home(__path)                              \
+    (weechat_plugin->string_expand_home)(__path)
 #define weechat_string_remove_quotes(__string, __quotes)                \
-    weechat_plugin->string_remove_quotes(__string, __quotes)
+    (weechat_plugin->string_remove_quotes)(__string, __quotes)
 #define weechat_string_strip(__string, __left, __right, __chars)        \
-    weechat_plugin->string_strip(__string, __left, __right, __chars)
+    (weechat_plugin->string_strip)(__string, __left, __right, __chars)
 #define weechat_string_convert_escaped_chars(__string)                  \
-    weechat_plugin->string_convert_escaped_chars(__string)
+    (weechat_plugin->string_convert_escaped_chars)(__string)
 #define weechat_string_mask_to_regex(__mask)                            \
-    weechat_plugin->string_mask_to_regex(__mask)
+    (weechat_plugin->string_mask_to_regex)(__mask)
 #define weechat_string_regex_flags(__regex, __default_flags, __flags)   \
-    weechat_plugin->string_regex_flags(__regex, __default_flags,        \
-                                       __flags)
+    (weechat_plugin->string_regex_flags)(__regex, __default_flags,      \
+                                         __flags)
 #define weechat_string_regcomp(__preg, __regex, __default_flags)        \
-    weechat_plugin->string_regcomp(__preg, __regex, __default_flags)
+    (weechat_plugin->string_regcomp)(__preg, __regex, __default_flags)
 #define weechat_string_has_highlight(__string, __highlight_words)       \
-    weechat_plugin->string_has_highlight(__string, __highlight_words)
+    (weechat_plugin->string_has_highlight)(__string, __highlight_words)
 #define weechat_string_has_highlight_regex(__string, __regex)           \
-    weechat_plugin->string_has_highlight_regex(__string, __regex)
+    (weechat_plugin->string_has_highlight_regex)(__string, __regex)
 #define weechat_string_replace_regex(__string, __regex, __replace,      \
                                      __reference_char, __callback,      \
                                      __callback_data)                   \
-    weechat_plugin->string_replace_regex(__string, __regex, __replace,  \
-                                         __reference_char, __callback,  \
-                                         __callback_data)
+    (weechat_plugin->string_replace_regex)(__string, __regex,           \
+                                           __replace,                   \
+                                           __reference_char,            \
+                                           __callback,                  \
+                                           __callback_data)
 #define weechat_string_split(__string, __separator, __eol, __max,       \
                              __num_items)                               \
-    weechat_plugin->string_split(__string, __separator, __eol,          \
-                                 __max, __num_items)
+    (weechat_plugin->string_split)(__string, __separator, __eol,        \
+                                   __max, __num_items)
 #define weechat_string_split_shell(__string, __num_items)               \
-    weechat_plugin->string_split_shell(__string, __num_items)
+    (weechat_plugin->string_split_shell)(__string, __num_items)
 #define weechat_string_free_split(__split_string)                       \
-    weechat_plugin->string_free_split(__split_string)
+    (weechat_plugin->string_free_split)(__split_string)
 #define weechat_string_build_with_split_string(__split_string,          \
                                                __separator)             \
-    weechat_plugin->string_build_with_split_string(__split_string,      \
-                                                   __separator)
+    (weechat_plugin->string_build_with_split_string)(__split_string,    \
+                                                     __separator)
 #define weechat_string_split_command(__command, __separator)            \
-    weechat_plugin->string_split_command(__command, __separator)
+    (weechat_plugin->string_split_command)(__command, __separator)
 #define weechat_string_free_split_command(__split_command)              \
-    weechat_plugin->string_free_split_command(__split_command)
+    (weechat_plugin->string_free_split_command)(__split_command)
 #define weechat_string_format_size(__size)                              \
-    weechat_plugin->string_format_size(__size)
+    (weechat_plugin->string_format_size)(__size)
 #define weechat_string_remove_color(__string, __replacement)            \
-    weechat_plugin->string_remove_color(__string, __replacement)
+    (weechat_plugin->string_remove_color)(__string, __replacement)
 #define weechat_string_encode_base64(__from, __length, __to)            \
-    weechat_plugin->string_encode_base64(__from, __length, __to)
+    (weechat_plugin->string_encode_base64)(__from, __length, __to)
 #define weechat_string_decode_base64(__from, __to)                      \
-    weechat_plugin->string_decode_base64(__from, __to)
+    (weechat_plugin->string_decode_base64)(__from, __to)
 #define weechat_string_is_command_char(__string)                        \
-    weechat_plugin->string_is_command_char(__string)
+    (weechat_plugin->string_is_command_char)(__string)
 #define weechat_string_input_for_buffer(__string)                       \
-    weechat_plugin->string_input_for_buffer(__string)
+    (weechat_plugin->string_input_for_buffer)(__string)
 #define weechat_string_eval_expression(__expr, __pointers,              \
                                        __extra_vars, __options)         \
-    weechat_plugin->string_eval_expression(__expr, __pointers,          \
-                                           __extra_vars, __options)
+    (weechat_plugin->string_eval_expression)(__expr, __pointers,        \
+                                             __extra_vars, __options)
 
 /* UTF-8 strings */
 #define weechat_utf8_has_8bits(__string)                                \
-    weechat_plugin->utf8_has_8bits(__string)
+    (weechat_plugin->utf8_has_8bits)(__string)
 #define weechat_utf8_is_valid(__string, __error)                        \
-    weechat_plugin->utf8_is_valid(__string, __error)
+    (weechat_plugin->utf8_is_valid)(__string, __error)
 #define weechat_utf8_normalize(__string, __char)                        \
-    weechat_plugin->utf8_normalize(__string, __char)
+    (weechat_plugin->utf8_normalize)(__string, __char)
 #define weechat_utf8_prev_char(__start, __string)                       \
-    weechat_plugin->utf8_prev_char(__start, __string)
+    (weechat_plugin->utf8_prev_char)(__start, __string)
 #define weechat_utf8_next_char(__string)                                \
-    weechat_plugin->utf8_next_char(__string)
+    (weechat_plugin->utf8_next_char)(__string)
 #define weechat_utf8_char_int(__string)                                 \
-    weechat_plugin->utf8_char_int(__string)
+    (weechat_plugin->utf8_char_int)(__string)
 #define weechat_utf8_char_size(__string)                                \
-    weechat_plugin->utf8_char_size(__string)
+    (weechat_plugin->utf8_char_size)(__string)
 #define weechat_utf8_strlen(__string)                                   \
-    weechat_plugin->utf8_strlen(__string)
+    (weechat_plugin->utf8_strlen)(__string)
 #define weechat_utf8_strnlen(__string, __bytes)                         \
-    weechat_plugin->utf8_strnlen(__string, __bytes)
+    (weechat_plugin->utf8_strnlen)(__string, __bytes)
 #define weechat_utf8_strlen_screen(__string)                            \
-    weechat_plugin->utf8_strlen_screen(__string)
+    (weechat_plugin->utf8_strlen_screen)(__string)
 #define weechat_utf8_charcmp(__string1, __string2)                      \
-    weechat_plugin->utf8_charcmp(__string1, __string2)
+    (weechat_plugin->utf8_charcmp)(__string1, __string2)
 #define weechat_utf8_charcasecmp(__string1, __string2)                  \
-    weechat_plugin->utf8_charcasecmp(__string1, __string2)
+    (weechat_plugin->utf8_charcasecmp)(__string1, __string2)
 #define weechat_utf8_char_size_screen(__string)                         \
-    weechat_plugin->utf8_char_size_screen(__string)
+    (weechat_plugin->utf8_char_size_screen)(__string)
 #define weechat_utf8_add_offset(__string, __offset)                     \
-    weechat_plugin->utf8_add_offset(__string, __offset)
+    (weechat_plugin->utf8_add_offset)(__string, __offset)
 #define weechat_utf8_real_pos(__string, __pos)                          \
-    weechat_plugin->utf8_real_pos(__string, __pos)
+    (weechat_plugin->utf8_real_pos)(__string, __pos)
 #define weechat_utf8_pos(__string, __real_pos)                          \
-    weechat_plugin->utf8_pos(__string, __real_pos)
+    (weechat_plugin->utf8_pos)(__string, __real_pos)
 #define weechat_utf8_strndup(__string, __length)                        \
-    weechat_plugin->utf8_strndup(__string, __length)
+    (weechat_plugin->utf8_strndup)(__string, __length)
 
 /* directories */
 #define weechat_mkdir_home(__directory, __mode)                         \
-    weechat_plugin->mkdir_home(__directory, __mode)
+    (weechat_plugin->mkdir_home)(__directory, __mode)
 #define weechat_mkdir(__directory, __mode)                              \
-    weechat_plugin->mkdir(__directory, __mode)
+    (weechat_plugin->mkdir)(__directory, __mode)
 #define weechat_mkdir_parents(__directory, __mode)                      \
-    weechat_plugin->mkdir_parents(__directory, __mode)
+    (weechat_plugin->mkdir_parents)(__directory, __mode)
 #define weechat_exec_on_files(__directory, __hidden_files, __data,      \
                               __callback)                               \
-    weechat_plugin->exec_on_files(__directory, __hidden_files, __data,  \
-                                  __callback)
+    (weechat_plugin->exec_on_files)(__directory, __hidden_files,        \
+                                    __data, __callback)
 #define weechat_file_get_content(__filename)                            \
-    weechat_plugin->file_get_content(__filename)
+    (weechat_plugin->file_get_content)(__filename)
 
 /* util */
 #define weechat_util_timeval_cmp(__time1, __time2)                      \
-    weechat_plugin->util_timeval_cmp(__time1, __time2)
+    (weechat_plugin->util_timeval_cmp)(__time1, __time2)
 #define weechat_util_timeval_diff(__time1, __time2)                     \
-    weechat_plugin->util_timeval_diff(__time1, __time2)
+    (weechat_plugin->util_timeval_diff)(__time1, __time2)
 #define weechat_util_timeval_add(__time, __interval)                    \
-    weechat_plugin->util_timeval_add(__time, __interval)
+    (weechat_plugin->util_timeval_add)(__time, __interval)
 #define weechat_util_get_time_string(__date)                            \
-    weechat_plugin->util_get_time_string(__date)
+    (weechat_plugin->util_get_time_string)(__date)
 #define weechat_util_version_number(__version)                          \
-    weechat_plugin->util_version_number(__version)
+    (weechat_plugin->util_version_number)(__version)
 
 /* sorted list */
 #define weechat_list_new()                                              \
-    weechat_plugin->list_new()
+    (weechat_plugin->list_new)()
 #define weechat_list_add(__list, __string, __where, __user_data)        \
-    weechat_plugin->list_add(__list, __string, __where, __user_data)
+    (weechat_plugin->list_add)(__list, __string, __where, __user_data)
 #define weechat_list_search(__list, __string)                           \
-    weechat_plugin->list_search(__list, __string)
+    (weechat_plugin->list_search)(__list, __string)
 #define weechat_list_search_pos(__list, __string)                       \
-    weechat_plugin->list_search_pos(__list, __string)
+    (weechat_plugin->list_search_pos)(__list, __string)
 #define weechat_list_casesearch(__list, __string)                       \
-    weechat_plugin->list_casesearch(__list, __string)
+    (weechat_plugin->list_casesearch)(__list, __string)
 #define weechat_list_casesearch_pos(__list, __string)                   \
-    weechat_plugin->list_casesearch_pos(__list, __string)
+    (weechat_plugin->list_casesearch_pos)(__list, __string)
 #define weechat_list_get(__list, __index)                               \
-    weechat_plugin->list_get(__list, __index)
+    (weechat_plugin->list_get)(__list, __index)
 #define weechat_list_set(__item, __value)                               \
-    weechat_plugin->list_set(__item, __value)
+    (weechat_plugin->list_set)(__item, __value)
 #define weechat_list_next(__item)                                       \
-    weechat_plugin->list_next(__item)
+    (weechat_plugin->list_next)(__item)
 #define weechat_list_prev(__item)                                       \
-    weechat_plugin->list_prev(__item)
+    (weechat_plugin->list_prev)(__item)
 #define weechat_list_string(__item)                                     \
-    weechat_plugin->list_string(__item)
+    (weechat_plugin->list_string)(__item)
 #define weechat_list_size(__list)                                       \
-    weechat_plugin->list_size(__list)
+    (weechat_plugin->list_size)(__list)
 #define weechat_list_remove(__list, __item)                             \
-    weechat_plugin->list_remove(__list, __item)
+    (weechat_plugin->list_remove)(__list, __item)
 #define weechat_list_remove_all(__list)                                 \
-    weechat_plugin->list_remove_all(__list)
+    (weechat_plugin->list_remove_all)(__list)
 #define weechat_list_free(__list)                                       \
-    weechat_plugin->list_free(__list)
+    (weechat_plugin->list_free)(__list)
 
 /* hash tables */
 #define weechat_hashtable_new(__size, __type_keys, __type_values,       \
                               __hash_key_cb, __keycmp_cb)               \
-    weechat_plugin->hashtable_new(__size, __type_keys, __type_values,   \
-                                  __hash_key_cb, __keycmp_cb)
+    (weechat_plugin->hashtable_new)(__size, __type_keys, __type_values, \
+                                    __hash_key_cb, __keycmp_cb)
 #define weechat_hashtable_set_with_size(__hashtable, __key, __key_size, \
                                         __value, __value_size)          \
-    weechat_plugin->hashtable_set_with_size(__hashtable, __key,         \
-                                            __key_size, __value,        \
-                                            __value_size)
+    (weechat_plugin->hashtable_set_with_size)(__hashtable, __key,       \
+                                              __key_size, __value,      \
+                                              __value_size)
 #define weechat_hashtable_set(__hashtable, __key, __value)              \
-    weechat_plugin->hashtable_set(__hashtable, __key, __value)
+    (weechat_plugin->hashtable_set)(__hashtable, __key, __value)
 #define weechat_hashtable_get(__hashtable, __key)                       \
-    weechat_plugin->hashtable_get(__hashtable, __key)
+    (weechat_plugin->hashtable_get)(__hashtable, __key)
 #define weechat_hashtable_has_key(__hashtable, __key)                   \
-    weechat_plugin->hashtable_has_key(__hashtable, __key)
+    (weechat_plugin->hashtable_has_key)(__hashtable, __key)
 #define weechat_hashtable_map(__hashtable, __cb_map, __cb_map_data)     \
-    weechat_plugin->hashtable_map(__hashtable, __cb_map, __cb_map_data)
+    (weechat_plugin->hashtable_map)(__hashtable, __cb_map,              \
+                                    __cb_map_data)
 #define weechat_hashtable_map_string(__hashtable, __cb_map,             \
                                      __cb_map_data)                     \
-    weechat_plugin->hashtable_map_string(__hashtable, __cb_map,         \
-                                         __cb_map_data)
+    (weechat_plugin->hashtable_map_string)(__hashtable, __cb_map,       \
+                                           __cb_map_data)
 #define weechat_hashtable_dup(__hashtable)                              \
-    weechat_plugin->hashtable_dup(__hashtable)
+    (weechat_plugin->hashtable_dup)(__hashtable)
 #define weechat_hashtable_get_integer(__hashtable, __property)          \
-    weechat_plugin->hashtable_get_integer(__hashtable, __property)
+    (weechat_plugin->hashtable_get_integer)(__hashtable, __property)
 #define weechat_hashtable_get_string(__hashtable, __property)           \
-    weechat_plugin->hashtable_get_string(__hashtable, __property)
+    (weechat_plugin->hashtable_get_string)(__hashtable, __property)
 #define weechat_hashtable_set_pointer(__hashtable, __property,          \
                                       __pointer)                        \
-    weechat_plugin->hashtable_set_pointer(__hashtable, __property,      \
-                                          __pointer)
+    (weechat_plugin->hashtable_set_pointer)(__hashtable, __property,    \
+                                            __pointer)
 #define weechat_hashtable_add_to_infolist(__hashtable, __infolist_item, \
                                           __prefix)                     \
-    weechat_plugin->hashtable_add_to_infolist(__hashtable,              \
-                                              __infolist_item,          \
-                                              __prefix)
+    (weechat_plugin->hashtable_add_to_infolist)(__hashtable,            \
+                                                __infolist_item,        \
+                                                __prefix)
 #define weechat_hashtable_remove(__hashtable, __key)                    \
-    weechat_plugin->hashtable_remove(__hashtable, __key)
+    (weechat_plugin->hashtable_remove)(__hashtable, __key)
 #define weechat_hashtable_remove_all(__hashtable)                       \
-    weechat_plugin->hashtable_remove_all(__hashtable)
+    (weechat_plugin->hashtable_remove_all)(__hashtable)
 #define weechat_hashtable_free(__hashtable)                             \
-    weechat_plugin->hashtable_free(__hashtable)
+    (weechat_plugin->hashtable_free)(__hashtable)
 
 /* config files */
 #define weechat_config_new(__name, __callback_reload,                   \
                            __callback_reload_data)                      \
-    weechat_plugin->config_new(weechat_plugin, __name,                  \
-                               __callback_reload,                       \
-                               __callback_reload_data)
+    (weechat_plugin->config_new)(weechat_plugin, __name,                \
+                                 __callback_reload,                     \
+                                 __callback_reload_data)
 #define weechat_config_new_section(__config, __name,                    \
                                    __user_can_add_options,              \
                                    __user_can_delete_options,           \
@@ -1214,20 +1217,20 @@ extern int weechat_plugin_end (struct t_
                                    __cb_create_option_data,             \
                                    __cb_delete_option,                  \
                                    __cb_delete_option_data)             \
-    weechat_plugin->config_new_section(__config, __name,                \
-                                       __user_can_add_options,          \
-                                       __user_can_delete_options,       \
-                                       __cb_read, __cb_read_data,       \
-                                       __cb_write_std,                  \
-                                       __cb_write_std_data,             \
-                                       __cb_write_def,                  \
-                                       __cb_write_def_data,             \
-                                       __cb_create_option,              \
-                                       __cb_create_option_data,         \
-                                       __cb_delete_option,              \
-                                       __cb_delete_option_data)
+    (weechat_plugin->config_new_section)(__config, __name,              \
+                                         __user_can_add_options,        \
+                                         __user_can_delete_options,     \
+                                         __cb_read, __cb_read_data,     \
+                                         __cb_write_std,                \
+                                         __cb_write_std_data,           \
+                                         __cb_write_def,                \
+                                         __cb_write_def_data,           \
+                                         __cb_create_option,            \
+                                         __cb_create_option_data,       \
+                                         __cb_delete_option,            \
+                                         __cb_delete_option_data)
 #define weechat_config_search_section(__config, __name)                 \
-    weechat_plugin->config_search_section(__config, __name)
+    (weechat_plugin->config_search_section)(__config, __name)
 #define weechat_config_new_option(__config, __section, __name, __type,  \
                                   __desc, __string_values, __min,       \
                                   __max, __default, __value,            \
@@ -1238,207 +1241,213 @@ extern int weechat_plugin_end (struct t_
                                   __callback_change_data,               \
                                   __callback_delete,                    \
                                   __callback_delete_data)               \
-    weechat_plugin->config_new_option(__config, __section, __name,      \
-                                      __type, __desc, __string_values,  \
-                                      __min, __max, __default, __value, \
-                                      __null_value_allowed,             \
-                                      __callback_check,                 \
-                                      __callback_check_data,            \
-                                      __callback_change,                \
-                                      __callback_change_data,           \
-                                      __callback_delete,                \
-                                      __callback_delete_data)
+    (weechat_plugin->config_new_option)(__config, __section, __name,    \
+                                        __type, __desc,                 \
+                                        __string_values,                \
+                                        __min, __max, __default,        \
+                                        __value,                        \
+                                        __null_value_allowed,           \
+                                        __callback_check,               \
+                                        __callback_check_data,          \
+                                        __callback_change,              \
+                                        __callback_change_data,         \
+                                        __callback_delete,              \
+                                        __callback_delete_data)
 #define weechat_config_search_option(__config, __section, __name)       \
-    weechat_plugin->config_search_option(__config, __section, __name)
+    (weechat_plugin->config_search_option)(__config, __section, __name)
 #define weechat_config_search_section_option(__config, __section,       \
                                              __name, __section_found,   \
                                              __option_found)            \
-    weechat_plugin->config_search_section_option(__config, __section,   \
-                                                 __name,                \
-                                                 __section_found,       \
-                                                 __option_found);
+    (weechat_plugin->config_search_section_option)(__config, __section, \
+                                                   __name,              \
+                                                   __section_found,     \
+                                                   __option_found);
 #define weechat_config_search_with_string(__name, __config, __section,  \
                                           __option, __pos_option)       \
-    weechat_plugin->config_search_with_string(__name, __config,         \
-                                              __section, __option,      \
-                                              __pos_option);
+    (weechat_plugin->config_search_with_string)(__name, __config,       \
+                                                __section, __option,    \
+                                                __pos_option);
 #define weechat_config_string_to_boolean(__string)                      \
-    weechat_plugin->config_string_to_boolean(__string)
+    (weechat_plugin->config_string_to_boolean)(__string)
 #define weechat_config_option_reset(__option, __run_callback)           \
-    weechat_plugin->config_option_reset(__option, __run_callback)
+    (weechat_plugin->config_option_reset)(__option, __run_callback)
 #define weechat_config_option_set(__option, __value, __run_callback)    \
-    weechat_plugin->config_option_set(__option, __value,                \
-                                      __run_callback)
+    (weechat_plugin->config_option_set)(__option, __value,              \
+                                        __run_callback)
 #define weechat_config_option_set_null(__option, __run_callback)        \
-    weechat_plugin->config_option_set_null(__option, __run_callback)
+    (weechat_plugin->config_option_set_null)(__option, __run_callback)
 #define weechat_config_option_unset(__option)                           \
-    weechat_plugin->config_option_unset(__option)
+    (weechat_plugin->config_option_unset)(__option)
 #define weechat_config_option_rename(__option, __new_name)              \
-    weechat_plugin->config_option_rename(__option, __new_name)
+    (weechat_plugin->config_option_rename)(__option, __new_name)
 #define weechat_config_option_get_pointer(__option, __property)         \
-    weechat_plugin->config_option_get_pointer(__option, __property)
+    (weechat_plugin->config_option_get_pointer)(__option, __property)
 #define weechat_config_option_is_null(__option)                         \
-    weechat_plugin->config_option_is_null(__option)
+    (weechat_plugin->config_option_is_null)(__option)
 #define weechat_config_option_default_is_null(__option)                 \
-    weechat_plugin->config_option_default_is_null(__option)
+    (weechat_plugin->config_option_default_is_null)(__option)
 #define weechat_config_boolean(__option)                                \
-    weechat_plugin->config_boolean(__option)
+    (weechat_plugin->config_boolean)(__option)
 #define weechat_config_boolean_default(__option)                        \
-    weechat_plugin->config_boolean_default(__option)
+    (weechat_plugin->config_boolean_default)(__option)
 #define weechat_config_integer(__option)                                \
-    weechat_plugin->config_integer(__option)
+    (weechat_plugin->config_integer)(__option)
 #define weechat_config_integer_default(__option)                        \
-    weechat_plugin->config_integer_default(__option)
+    (weechat_plugin->config_integer_default)(__option)
 #define weechat_config_string(__option)                                 \
-    weechat_plugin->config_string(__option)
+    (weechat_plugin->config_string)(__option)
 #define weechat_config_string_default(__option)                         \
-    weechat_plugin->config_string_default(__option)
+    (weechat_plugin->config_string_default)(__option)
 #define weechat_config_color(__option)                                  \
-    weechat_plugin->config_color(__option)
+    (weechat_plugin->config_color)(__option)
 #define weechat_config_color_default(__option)                          \
-    weechat_plugin->config_color_default(__option)
+    (weechat_plugin->config_color_default)(__option)
 #define weechat_config_write_option(__config, __option)                 \
-    weechat_plugin->config_write_option(__config, __option)
+    (weechat_plugin->config_write_option)(__config, __option)
 #define weechat_config_write_line(__config, __option, __value...)       \
-    weechat_plugin->config_write_line(__config, __option, ##__value)
+    (weechat_plugin->config_write_line)(__config, __option, ##__value)
 #define weechat_config_write(__config)                                  \
-    weechat_plugin->config_write(__config)
+    (weechat_plugin->config_write)(__config)
 #define weechat_config_read(__config)                                   \
-    weechat_plugin->config_read(__config)
+    (weechat_plugin->config_read)(__config)
 #define weechat_config_reload(__config)                                 \
-    weechat_plugin->config_reload(__config)
+    (weechat_plugin->config_reload)(__config)
 #define weechat_config_option_free(__option)                            \
-    weechat_plugin->config_option_free(__option)
+    (weechat_plugin->config_option_free)(__option)
 #define weechat_config_section_free_options(__section)                  \
-    weechat_plugin->config_section_free_options(__section)
+    (weechat_plugin->config_section_free_options)(__section)
 #define weechat_config_section_free(__section)                          \
-    weechat_plugin->config_section_free(__section)
+    (weechat_plugin->config_section_free)(__section)
 #define weechat_config_free(__config)                                   \
-    weechat_plugin->config_free(__config)
+    (weechat_plugin->config_free)(__config)
 #define weechat_config_get(__option)                                    \
-    weechat_plugin->config_get(__option)
+    (weechat_plugin->config_get)(__option)
 #define weechat_config_get_plugin(__option)                             \
-    weechat_plugin->config_get_plugin(weechat_plugin, __option)
+    (weechat_plugin->config_get_plugin)(weechat_plugin, __option)
 #define weechat_config_is_set_plugin(__option)                          \
-    weechat_plugin->config_is_set_plugin(weechat_plugin, __option)
+    (weechat_plugin->config_is_set_plugin)(weechat_plugin, __option)
 #define weechat_config_set_plugin(__option, __value)                    \
-    weechat_plugin->config_set_plugin(weechat_plugin, __option,         \
-                                      __value)
+    (weechat_plugin->config_set_plugin)(weechat_plugin, __option,       \
+                                        __value)
 #define weechat_config_set_desc_plugin(__option, __description)         \
-    weechat_plugin->config_set_desc_plugin(weechat_plugin, __option,    \
-                                      __description)
+    (weechat_plugin->config_set_desc_plugin)(weechat_plugin, __option,  \
+                                             __description)
 #define weechat_config_unset_plugin(__option)                           \
-    weechat_plugin->config_unset_plugin(weechat_plugin, __option)
+    (weechat_plugin->config_unset_plugin)(weechat_plugin, __option)
 
 /* key bindings */
 #define weechat_key_bind(__context, __keys)                             \
-    weechat_plugin->key_bind(__context, __keys)
+    (weechat_plugin->key_bind)(__context, __keys)
 #define weechat_key_unbind(__context, __key)                            \
-    weechat_plugin->key_unbind(__context, __key)
+    (weechat_plugin->key_unbind)(__context, __key)
 
 /* display */
 #define weechat_prefix(__prefix)                                        \
-    weechat_plugin->prefix(__prefix)
+    (weechat_plugin->prefix)(__prefix)
 #define weechat_color(__color_name)                                     \
-    weechat_plugin->color(__color_name)
+    (weechat_plugin->color)(__color_name)
 #define weechat_printf(__buffer, __message, __argz...)                  \
-    weechat_plugin->printf_date_tags(__buffer, 0, NULL, __message,      \
-                                     ##__argz)
+    (weechat_plugin->printf_date_tags)(__buffer, 0, NULL, __message,    \
+                                       ##__argz)
 #define weechat_printf_date(__buffer, __date, __message, __argz...)     \
-    weechat_plugin->printf_date_tags(__buffer, __date, NULL,            \
-                                     __message, ##__argz)
+    (weechat_plugin->printf_date_tags)(__buffer, __date, NULL,          \
+                                       __message, ##__argz)
 #define weechat_printf_tags(__buffer, __tags, __message, __argz...)     \
-    weechat_plugin->printf_date_tags(__buffer, 0, __tags, __message,    \
-                                     ##__argz)
+    (weechat_plugin->printf_date_tags)(__buffer, 0, __tags, __message,  \
+                                       ##__argz)
 #define weechat_printf_date_tags(__buffer, __date, __tags, __message,   \
                                  __argz...)                             \
-    weechat_plugin->printf_date_tags(__buffer, __date, __tags,          \
-                                     __message, ##__argz)
+    (weechat_plugin->printf_date_tags)(__buffer, __date, __tags,        \
+                                       __message, ##__argz)
 #define weechat_printf_y(__buffer, __y, __message, __argz...)           \
-    weechat_plugin->printf_y(__buffer, __y, __message, ##__argz)
+    (weechat_plugin->printf_y)(__buffer, __y, __message, ##__argz)
 #define weechat_log_printf(__message, __argz...)                        \
-    weechat_plugin->log_printf(__message, ##__argz)
+    (weechat_plugin->log_printf)(__message, ##__argz)
 
 /* hooks */
 #define weechat_hook_command(__command, __description, __args,          \
                              __args_desc, __completion, __callback,     \
                              __data)                                    \
-    weechat_plugin->hook_command(weechat_plugin, __command,             \
-                                 __description, __args, __args_desc,    \
-                                 __completion, __callback, __data)
+    (weechat_plugin->hook_command)(weechat_plugin, __command,           \
+                                   __description, __args, __args_desc,  \
+                                   __completion, __callback, __data)
 #define weechat_hook_command_run(__command, __callback, __data)         \
-    weechat_plugin->hook_command_run(weechat_plugin, __command,         \
-                                     __callback, __data)
+    (weechat_plugin->hook_command_run)(weechat_plugin, __command,       \
+                                       __callback, __data)
 #define weechat_hook_timer(__interval, __align_second, __max_calls,     \
                            __callback, __data)                          \
-    weechat_plugin->hook_timer(weechat_plugin, __interval,              \
-                               __align_second, __max_calls,             \
-                               __callback, __data)
+    (weechat_plugin->hook_timer)(weechat_plugin, __interval,            \
+                                 __align_second, __max_calls,           \
+                                 __callback, __data)
 #define weechat_hook_fd(__fd, __flag_read, __flag_write,                \
                         __flag_exception, __callback, __data)           \
-    weechat_plugin->hook_fd(weechat_plugin, __fd, __flag_read,          \
-                            __flag_write, __flag_exception, __callback, \
-                            __data)
+    (weechat_plugin->hook_fd)(weechat_plugin, __fd, __flag_read,        \
+                              __flag_write, __flag_exception,           \
+                              __callback, __data)
 #define weechat_hook_process(__command, __timeout, __callback,          \
                              __callback_data)                           \
-    weechat_plugin->hook_process(weechat_plugin, __command, __timeout,  \
-                                 __callback, __callback_data)
+    (weechat_plugin->hook_process)(weechat_plugin, __command,           \
+                                   __timeout, __callback,               \
+                                   __callback_data)
 #define weechat_hook_process_hashtable(__command, __options, __timeout, \
                                        __callback, __callback_data)     \
-    weechat_plugin->hook_process_hashtable(weechat_plugin, __command,   \
-                                           __options, __timeout,        \
-                                            __callback, __callback_data)
+    (weechat_plugin->hook_process_hashtable)(weechat_plugin, __command, \
+                                             __options, __timeout,      \
+                                             __callback,                \
+                                             __callback_data)
 #define weechat_hook_connect(__proxy, __address, __port, __ipv6,        \
                              __retry, __gnutls_sess, __gnutls_cb,       \
                              __gnutls_dhkey_size, __gnutls_priorities,  \
                              __local_hostname, __callback, __data)      \
-    weechat_plugin->hook_connect(weechat_plugin, __proxy, __address,    \
-                                 __port, __ipv6, __retry,               \
-                                 __gnutls_sess, __gnutls_cb,            \
-                                 __gnutls_dhkey_size,                   \
-                                 __gnutls_priorities, __local_hostname, \
-                                 __callback, __data)
+    (weechat_plugin->hook_connect)(weechat_plugin, __proxy, __address,  \
+                                   __port, __ipv6, __retry,             \
+                                   __gnutls_sess, __gnutls_cb,          \
+                                   __gnutls_dhkey_size,                 \
+                                   __gnutls_priorities,                 \
+                                   __local_hostname,                    \
+                                   __callback, __data)
 #define weechat_hook_print(__buffer, __tags, __msg, __strip__colors,    \
                            __callback, __data)                          \
-    weechat_plugin->hook_print(weechat_plugin, __buffer, __tags,        \
-                               __msg, __strip__colors, __callback,      \
-                               __data)
+    (weechat_plugin->hook_print)(weechat_plugin, __buffer, __tags,      \
+                                 __msg, __strip__colors, __callback,    \
+                                 __data)
 #define weechat_hook_signal(__signal, __callback, __data)               \
-    weechat_plugin->hook_signal(weechat_plugin, __signal, __callback,   \
-                                __data)
+    (weechat_plugin->hook_signal)(weechat_plugin, __signal, __callback, \
+                                  __data)
 #define weechat_hook_signal_send(__signal, __type_data, __signal_data)  \
-    weechat_plugin->hook_signal_send(__signal, __type_data,             \
-                                     __signal_data)
+    (weechat_plugin->hook_signal_send)(__signal, __type_data,           \
+                                       __signal_data)
 #define weechat_hook_hsignal(__signal, __callback, __data)              \
-    weechat_plugin->hook_hsignal(weechat_plugin, __signal, __callback,  \
-                                __data)
+    (weechat_plugin->hook_hsignal)(weechat_plugin, __signal,            \
+                                   __callback, __data)
 #define weechat_hook_hsignal_send(__signal, __hashtable)                \
-    weechat_plugin->hook_hsignal_send(__signal, __hashtable)
+    (weechat_plugin->hook_hsignal_send)(__signal, __hashtable)
 #define weechat_hook_config(__option, __callback, __data)               \
-    weechat_plugin->hook_config(weechat_plugin, __option, __callback,   \
-                                __data)
+    (weechat_plugin->hook_config)(weechat_plugin, __option, __callback, \
+                                  __data)
 #define weechat_hook_completion(__completion, __description,            \
                                 __callback, __data)                     \
-    weechat_plugin->hook_completion(weechat_plugin, __completion,       \
-                                    __description, __callback, __data)
+    (weechat_plugin->hook_completion)(weechat_plugin, __completion,     \
+                                      __description, __callback,        \
+                                      __data)
 #define weechat_hook_completion_get_string(__completion, __property)    \
-    weechat_plugin->hook_completion_get_string(__completion,            \
-                                               __property)
+    (weechat_plugin->hook_completion_get_string)(__completion,          \
+                                                 __property)
 #define weechat_hook_completion_list_add(__completion, __word,          \
                                          __nick_completion, __where)    \
-    weechat_plugin->hook_completion_list_add(__completion, __word,      \
-                                             __nick_completion,         \
-                                             __where)
+    (weechat_plugin->hook_completion_list_add)(__completion, __word,    \
+                                               __nick_completion,       \
+                                               __where)
 #define weechat_hook_modifier(__modifier, __callback, __data)           \
-    weechat_plugin->hook_modifier(weechat_plugin, __modifier,           \
-                                  __callback, __data)
+    (weechat_plugin->hook_modifier)(weechat_plugin, __modifier,         \
+                                    __callback, __data)
 #define weechat_hook_modifier_exec(__modifier, __modifier_data,         \
                                    __string)                            \
-    weechat_plugin->hook_modifier_exec(weechat_plugin, __modifier,      \
-                                       __modifier_data, __string)
+    (weechat_plugin->hook_modifier_exec)(weechat_plugin, __modifier,    \
+                                         __modifier_data, __string)
 #define weechat_hook_info(__info_name, __description,                   \
                           __args_description, __callback, __data)       \
-    weechat_plugin->hook_info(weechat_plugin, __info_name,              \
+    (weechat_plugin->hook_info)(weechat_plugin, __info_name,            \
                               __description, __args_description,        \
                               __callback, __data)
 #define weechat_hook_info_hashtable(__info_name, __description,         \
@@ -1446,316 +1455,328 @@ extern int weechat_plugin_end (struct t_
                                     __output_description,               \
                                     __callback,                         \
                                     __data)                             \
-    weechat_plugin->hook_info_hashtable(weechat_plugin, __info_name,    \
-                                        __description,                  \
-                                        __args_description,             \
-                                        __output_description,           \
-                                        __callback, __data)
+    (weechat_plugin->hook_info_hashtable)(weechat_plugin, __info_name,  \
+                                          __description,                \
+                                          __args_description,           \
+                                          __output_description,         \
+                                          __callback, __data)
 #define weechat_hook_infolist(__infolist_name, __description,           \
                               __pointer_description,                    \
                               __args_description, __callback, __data)   \
-    weechat_plugin->hook_infolist(weechat_plugin, __infolist_name,      \
-                                  __description, __pointer_description, \
-                                  __args_description, __callback,       \
-                                  __data)
+    (weechat_plugin->hook_infolist)(weechat_plugin, __infolist_name,    \
+                                    __description,                      \
+                                    __pointer_description,              \
+                                    __args_description, __callback,     \
+                                    __data)
 #define weechat_hook_hdata(__hdata_name, __description, __callback,     \
                            __data)                                      \
-    weechat_plugin->hook_hdata(weechat_plugin, __hdata_name,            \
-                               __description, __callback, __data)
+    (weechat_plugin->hook_hdata)(weechat_plugin, __hdata_name,          \
+                                 __description, __callback, __data)
 #define weechat_hook_focus(__area, __callback, __data)                  \
-    weechat_plugin->hook_focus(weechat_plugin, __area, __callback,      \
-                               __data)
+    (weechat_plugin->hook_focus)(weechat_plugin, __area, __callback,    \
+                                 __data)
 #define weechat_hook_set(__hook, __property, __value)                   \
-    weechat_plugin->hook_set(__hook, __property, __value)
+    (weechat_plugin->hook_set)(__hook, __property, __value)
 #define weechat_unhook(__hook)                                          \
-    weechat_plugin->unhook( __hook)
+    (weechat_plugin->unhook)( __hook)
 #define weechat_unhook_all()                                            \
-    weechat_plugin->unhook_all_plugin(weechat_plugin)
+    (weechat_plugin->unhook_all_plugin)(weechat_plugin)
 
 /* buffers */
 #define weechat_buffer_new(__name, __input_callback,                    \
                            __input_callback_data, __close_callback,     \
                            __close_callback_data)                       \
-    weechat_plugin->buffer_new(weechat_plugin, __name,                  \
-                               __input_callback, __input_callback_data, \
-                               __close_callback, __close_callback_data)
+    (weechat_plugin->buffer_new)(weechat_plugin, __name,                \
+                                 __input_callback,                      \
+                                 __input_callback_data,                 \
+                                 __close_callback,                      \
+                                 __close_callback_data)
 #define weechat_buffer_search(__plugin, __name)                         \
-    weechat_plugin->buffer_search(__plugin, __name)
+    (weechat_plugin->buffer_search)(__plugin, __name)
 #define weechat_buffer_search_main()                                    \
-    weechat_plugin->buffer_search_main()
+    (weechat_plugin->buffer_search_main)()
 #define weechat_current_buffer()                                        \
-    weechat_plugin->buffer_search(NULL, NULL)
+    (weechat_plugin->buffer_search)(NULL, NULL)
 #define weechat_buffer_clear(__buffer)                                  \
-    weechat_plugin->buffer_clear(__buffer)
+    (weechat_plugin->buffer_clear)(__buffer)
 #define weechat_buffer_close(__buffer)                                  \
-    weechat_plugin->buffer_close(__buffer)
+    (weechat_plugin->buffer_close)(__buffer)
 #define weechat_buffer_merge(__buffer, __target_buffer)                 \
-    weechat_plugin->buffer_merge(__buffer, __target_buffer)
+    (weechat_plugin->buffer_merge)(__buffer, __target_buffer)
 #define weechat_buffer_unmerge(__buffer, __number)                      \
-    weechat_plugin->buffer_unmerge(__buffer, __number)
+    (weechat_plugin->buffer_unmerge)(__buffer, __number)
 #define weechat_buffer_get_integer(__buffer, __property)                \
-    weechat_plugin->buffer_get_integer(__buffer, __property)
+    (weechat_plugin->buffer_get_integer)(__buffer, __property)
 #define weechat_buffer_get_string(__buffer, __property)                 \
-    weechat_plugin->buffer_get_string(__buffer, __property)
+    (weechat_plugin->buffer_get_string)(__buffer, __property)
 #define weechat_buffer_get_pointer(__buffer, __property)                \
-    weechat_plugin->buffer_get_pointer(__buffer, __property)
+    (weechat_plugin->buffer_get_pointer)(__buffer, __property)
 #define weechat_buffer_set(__buffer, __property, __value)               \
-    weechat_plugin->buffer_set(__buffer, __property, __value)
+    (weechat_plugin->buffer_set)(__buffer, __property, __value)
 #define weechat_buffer_set_pointer(__buffer, __property, __pointer)     \
-    weechat_plugin->buffer_set_pointer(__buffer, __property, __pointer)
+    (weechat_plugin->buffer_set_pointer)(__buffer, __property,          \
+                                         __pointer)
 #define weechat_buffer_string_replace_local_var(__buffer, __string)     \
-    weechat_plugin->buffer_string_replace_local_var(__buffer, __string)
+    (weechat_plugin->buffer_string_replace_local_var)(__buffer,         \
+                                                      __string)
 #define weechat_buffer_match_list(__buffer, __string)                   \
-    weechat_plugin->buffer_match_list(__buffer, __string)
+    (weechat_plugin->buffer_match_list)(__buffer, __string)
 
 /* windows */
 #define weechat_window_search_with_buffer(__buffer)                     \
-    weechat_plugin->window_search_with_buffer(__buffer)
+    (weechat_plugin->window_search_with_buffer)(__buffer)
 #define weechat_window_get_integer(__window, __property)                \
-    weechat_plugin->window_get_integer(__window, __property)
+    (weechat_plugin->window_get_integer)(__window, __property)
 #define weechat_window_get_string(__window, __property)                 \
-    weechat_plugin->window_get_string(__window, __property)
+    (weechat_plugin->window_get_string)(__window, __property)
 #define weechat_window_get_pointer(__window, __property)                \
-    weechat_plugin->window_get_pointer(__window, __property)
+    (weechat_plugin->window_get_pointer)(__window, __property)
 #define weechat_current_window()                                        \
-    weechat_plugin->window_get_pointer(NULL, "current")
+    (weechat_plugin->window_get_pointer)(NULL, "current")
 #define weechat_window_set_title(__title)                               \
-    weechat_plugin->window_set_title(__title)
+    (weechat_plugin->window_set_title)(__title)
 
 /* nicklist */
 #define weechat_nicklist_add_group(__buffer, __parent_group, __name,    \
                                    __color, __visible)                  \
-    weechat_plugin->nicklist_add_group(__buffer, __parent_group,        \
-                                       __name, __color, __visible)
+    (weechat_plugin->nicklist_add_group)(__buffer, __parent_group,      \
+                                         __name, __color, __visible)
 #define weechat_nicklist_search_group(__buffer, __from_group, __name)   \
-    weechat_plugin->nicklist_search_group(__buffer, __from_group,       \
-                                          __name)
+    (weechat_plugin->nicklist_search_group)(__buffer, __from_group,     \
+                                            __name)
 #define weechat_nicklist_add_nick(__buffer, __group, __name, __color,   \
                                   __prefix, __prefix_color, __visible)  \
-    weechat_plugin->nicklist_add_nick(__buffer, __group, __name,        \
-                                      __color, __prefix,                \
-                                      __prefix_color, __visible)
+    (weechat_plugin->nicklist_add_nick)(__buffer, __group, __name,      \
+                                        __color, __prefix,              \
+                                        __prefix_color, __visible)
 #define weechat_nicklist_search_nick(__buffer, __from_group, __name)    \
-    weechat_plugin->nicklist_search_nick(__buffer, __from_group,        \
-                                         __name)
+    (weechat_plugin->nicklist_search_nick)(__buffer, __from_group,      \
+                                           __name)
 #define weechat_nicklist_remove_group(__buffer, __group)                \
-    weechat_plugin->nicklist_remove_group(__buffer, __group)
+    (weechat_plugin->nicklist_remove_group)(__buffer, __group)
 #define weechat_nicklist_remove_nick(__buffer, __nick)                  \
-    weechat_plugin->nicklist_remove_nick(__buffer, __nick)
+    (weechat_plugin->nicklist_remove_nick)(__buffer, __nick)
 #define weechat_nicklist_remove_all(__buffer)                           \
-    weechat_plugin->nicklist_remove_all(__buffer)
+    (weechat_plugin->nicklist_remove_all)(__buffer)
 #define weechat_nicklist_get_next_item(__buffer, __group, __nick)       \
-    weechat_plugin->nicklist_get_next_item(__buffer, __group, __nick)
+    (weechat_plugin->nicklist_get_next_item)(__buffer, __group, __nick)
 #define weechat_nicklist_group_get_integer(__buffer, __group,           \
                                            __property)                  \
-    weechat_plugin->nicklist_group_get_integer(__buffer, __group,       \
-                                               __property)
+    (weechat_plugin->nicklist_group_get_integer)(__buffer, __group,     \
+                                                 __property)
 #define weechat_nicklist_group_get_string(__buffer, __group,            \
                                           __property)                   \
-    weechat_plugin->nicklist_group_get_string(__buffer, __group,        \
-                                              __property)
+    (weechat_plugin->nicklist_group_get_string)(__buffer, __group,      \
+                                                __property)
 #define weechat_nicklist_group_get_pointer(__buffer, __group,           \
                                            __property)                  \
-    weechat_plugin->nicklist_group_get_pointer(__buffer, __group,       \
-                                               __property)
+    (weechat_plugin->nicklist_group_get_pointer)(__buffer, __group,     \
+                                                 __property)
 #define weechat_nicklist_group_set(__buffer, __group, __property,       \
                                    __value)                             \
-    weechat_plugin->nicklist_group_set(__buffer, __group, __property,   \
-                                       __value)
+    (weechat_plugin->nicklist_group_set)(__buffer, __group, __property, \
+                                         __value)
 #define weechat_nicklist_nick_get_integer(__buffer, __nick, __property) \
-    weechat_plugin->nicklist_nick_get_integer(__buffer, __nick,         \
-                                              __property)
+    (weechat_plugin->nicklist_nick_get_integer)(__buffer, __nick,       \
+                                                __property)
 #define weechat_nicklist_nick_get_string(__buffer, __nick, __property)  \
-    weechat_plugin->nicklist_nick_get_string(__buffer, __nick,          \
-                                             __property)
+    (weechat_plugin->nicklist_nick_get_string)(__buffer, __nick,        \
+                                               __property)
 #define weechat_nicklist_nick_get_pointer(__buffer, __nick, __property) \
-    weechat_plugin->nicklist_nick_get_pointer(__buffer, __nick,         \
-                                              __property)
+    (weechat_plugin->nicklist_nick_get_pointer)(__buffer, __nick,       \
+                                                __property)
 #define weechat_nicklist_nick_set(__buffer, __nick, __property,         \
                                   __value)                              \
-    weechat_plugin->nicklist_nick_set(__buffer, __nick, __property,     \
-                                      __value)
+    (weechat_plugin->nicklist_nick_set)(__buffer, __nick, __property,   \
+                                        __value)
 
 /* bars */
 #define weechat_bar_item_search(__name)                                 \
-    weechat_plugin->bar_item_search(__name)
+    (weechat_plugin->bar_item_search)(__name)
 #define weechat_bar_item_new(__name, __build_callback, __data)          \
-    weechat_plugin->bar_item_new(weechat_plugin, __name,                \
-                                 __build_callback, __data)
+    (weechat_plugin->bar_item_new)(weechat_plugin, __name,              \
+                                   __build_callback, __data)
 #define weechat_bar_item_update(__name)                                 \
-    weechat_plugin->bar_item_update(__name)
+    (weechat_plugin->bar_item_update)(__name)
 #define weechat_bar_item_remove(__item)                                 \
-    weechat_plugin->bar_item_remove(__item)
+    (weechat_plugin->bar_item_remove)(__item)
 #define weechat_bar_search(__name)                                      \
-    weechat_plugin->bar_search(__name)
+    (weechat_plugin->bar_search)(__name)
 #define weechat_bar_new(__name, __hidden, __priority, __type,           \
                         __condition, __position, __filling_top_bottom,  \
                         __filling_left_right, __size, __size_max,       \
                         __color_fg, __color_delim, __color_bg,          \
                         __separator, __items)                           \
-    weechat_plugin->bar_new(__name, __hidden, __priority, __type,       \
-                            __condition, __position,                    \
-                            __filling_top_bottom, __filling_left_right, \
-                            __size, __size_max, __color_fg,             \
-                            __color_delim, __color_bg, __separator,     \
-                            __items)
+    (weechat_plugin->bar_new)(__name, __hidden, __priority, __type,     \
+                              __condition, __position,                  \
+                              __filling_top_bottom,                     \
+                              __filling_left_right,                     \
+                              __size, __size_max, __color_fg,           \
+                              __color_delim, __color_bg, __separator,   \
+                              __items)
 #define weechat_bar_set(__bar, __property, __value)                     \
-    weechat_plugin->bar_set(__bar, __property, __value)
+    (weechat_plugin->bar_set)(__bar, __property, __value)
 #define weechat_bar_update(__name)                                      \
-    weechat_plugin->bar_update(__name)
+    (weechat_plugin->bar_update)(__name)
 #define weechat_bar_remove(__bar)                                       \
-    weechat_plugin->bar_remove(__bar)
+    (weechat_plugin->bar_remove)(__bar)
 
 /* command */
 #define weechat_command(__buffer, __command)                            \
-    weechat_plugin->command(weechat_plugin, __buffer, __command)
+    (weechat_plugin->command)(weechat_plugin, __buffer, __command)
 
 /* network */
 #define weechat_network_pass_proxy(__proxy, __sock, __address, __port)  \
-    weechat_plugin->network_pass_proxy(__proxy, __sock, __address,      \
-                                       __port)
+    (weechat_plugin->network_pass_proxy)(__proxy, __sock, __address,    \
+                                         __port)
 #define weechat_network_connect_to(__proxy, __address,                  \
                                    __address_length)                    \
-    weechat_plugin->network_connect_to(__proxy, __address,              \
-                                       __address_length)
+    (weechat_plugin->network_connect_to)(__proxy, __address,            \
+                                         __address_length)
 
 /* infos */
 #define weechat_info_get(__info_name, __arguments)                      \
-    weechat_plugin->info_get(weechat_plugin, __info_name, __arguments)
+    (weechat_plugin->info_get)(weechat_plugin, __info_name,             \
+                               __arguments)
 #define weechat_info_get_hashtable(__info_name, __hashtable)            \
-    weechat_plugin->info_get_hashtable(weechat_plugin, __info_name,     \
-                                       __hashtable)
+    (weechat_plugin->info_get_hashtable)(weechat_plugin, __info_name,   \
+                                         __hashtable)
 
 /* infolists */
 #define weechat_infolist_new()                                          \
-    weechat_plugin->infolist_new(weechat_plugin)
+    (weechat_plugin->infolist_new)(weechat_plugin)
 #define weechat_infolist_new_item(__list)                               \
-    weechat_plugin->infolist_new_item(__list)
+    (weechat_plugin->infolist_new_item)(__list)
 #define weechat_infolist_new_var_integer(__item, __name, __value)       \
-    weechat_plugin->infolist_new_var_integer(__item, __name, __value)
+    (weechat_plugin->infolist_new_var_integer)(__item, __name, __value)
 #define weechat_infolist_new_var_string(__item, __name, __value)        \
-    weechat_plugin->infolist_new_var_string(__item, __name, __value)
+    (weechat_plugin->infolist_new_var_string)(__item, __name, __value)
 #define weechat_infolist_new_var_pointer(__item, __name, __pointer)     \
-    weechat_plugin->infolist_new_var_pointer(__item, __name, __pointer)
+    (weechat_plugin->infolist_new_var_pointer)(__item, __name,          \
+                                               __pointer)
 #define weechat_infolist_new_var_buffer(__item, __name, __buffer,       \
                                         __size)                         \
-    weechat_plugin->infolist_new_var_buffer(__item, __name, __buffer,   \
-                                            __size)
+    (weechat_plugin->infolist_new_var_buffer)(__item, __name, __buffer, \
+                                              __size)
 #define weechat_infolist_new_var_time(__item, __name, __time)           \
-    weechat_plugin->infolist_new_var_time(__item, __name, __time)
+    (weechat_plugin->infolist_new_var_time)(__item, __name, __time)
 #define weechat_infolist_search_var(__list, __name)                     \
-    weechat_plugin->infolist_search_var(__list, __name)
+    (weechat_plugin->infolist_search_var)(__list, __name)
 #define weechat_infolist_get(__infolist_name, __pointer, __arguments)   \
-    weechat_plugin->infolist_get(weechat_plugin, __infolist_name,       \
-                                 __pointer, __arguments)
+    (weechat_plugin->infolist_get)(weechat_plugin, __infolist_name,     \
+                                   __pointer, __arguments)
 #define weechat_infolist_next(__list)                                   \
-    weechat_plugin->infolist_next(__list)
+    (weechat_plugin->infolist_next)(__list)
 #define weechat_infolist_prev(__list)                                   \
-    weechat_plugin->infolist_prev(__list)
+    (weechat_plugin->infolist_prev)(__list)
 #define weechat_infolist_reset_item_cursor(__list)                      \
-    weechat_plugin->infolist_reset_item_cursor(__list)
+    (weechat_plugin->infolist_reset_item_cursor)(__list)
 #define weechat_infolist_fields(__list)                                 \
-    weechat_plugin->infolist_fields(__list)
+    (weechat_plugin->infolist_fields)(__list)
 #define weechat_infolist_integer(__item, __var)                         \
-    weechat_plugin->infolist_integer(__item, __var)
+    (weechat_plugin->infolist_integer)(__item, __var)
 #define weechat_infolist_string(__item, __var)                          \
-    weechat_plugin->infolist_string(__item, __var)
+    (weechat_plugin->infolist_string)(__item, __var)
 #define weechat_infolist_pointer(__item, __var)                         \
-    weechat_plugin->infolist_pointer(__item, __var)
+    (weechat_plugin->infolist_pointer)(__item, __var)
 #define weechat_infolist_buffer(__item, __var, __size)                  \
-    weechat_plugin->infolist_buffer(__item, __var, __size)
+    (weechat_plugin->infolist_buffer)(__item, __var, __size)
 #define weechat_infolist_time(__item, __var)                            \
-    weechat_plugin->infolist_time(__item, __var)
+    (weechat_plugin->infolist_time)(__item, __var)
 #define weechat_infolist_free(__list)                                   \
-    weechat_plugin->infolist_free(__list)
+    (weechat_plugin->infolist_free)(__list)
 
 /* hdata */
 #define weechat_hdata_new(__hdata_name, __var_prev, __var_next,         \
                           __create_allowed, __delete_allowed,           \
                           __callback_update, __callback_update_data)    \
-    weechat_plugin->hdata_new(weechat_plugin, __hdata_name, __var_prev, \
-                              __var_next, __create_allowed,             \
-                              __delete_allowed, __callback_update,      \
-                              __callback_update_data)
+    (weechat_plugin->hdata_new)(weechat_plugin, __hdata_name,           \
+                                __var_prev, __var_next,                 \
+                                __create_allowed, __delete_allowed,     \
+                                __callback_update,                      \
+                                __callback_update_data)
 #define weechat_hdata_new_var(__hdata, __name, __offset, __type,        \
                               __update_allowed, __array_size,           \
                               __hdata_name)                             \
-    weechat_plugin->hdata_new_var(__hdata, __name, __offset, __type,    \
-                                  __update_allowed, __array_size,       \
-                                  __hdata_name)
+    (weechat_plugin->hdata_new_var)(__hdata, __name, __offset, __type,  \
+                                    __update_allowed, __array_size,     \
+                                    __hdata_name)
 #define WEECHAT_HDATA_VAR(__struct, __name, __type, __update_allowed,   \
                           __array_size, __hdata_name)                   \
     weechat_hdata_new_var (hdata, #__name, offsetof (__struct, __name), \
                            WEECHAT_HDATA_##__type, __update_allowed,    \
                            __array_size, __hdata_name)
 #define weechat_hdata_new_list(__hdata, __name, __pointer, __flags)     \
-    weechat_plugin->hdata_new_list(__hdata, __name, __pointer, __flags)
+    (weechat_plugin->hdata_new_list)(__hdata, __name, __pointer,        \
+                                     __flags)
 #define WEECHAT_HDATA_LIST(__name, __flags)                             \
     weechat_hdata_new_list (hdata, #__name, &(__name), __flags);
 #define weechat_hdata_get(__hdata_name)                                 \
-    weechat_plugin->hdata_get(weechat_plugin, __hdata_name)
+    (weechat_plugin->hdata_get)(weechat_plugin, __hdata_name)
 #define weechat_hdata_get_var_offset(__hdata, __name)                   \
-    weechat_plugin->hdata_get_var_offset(__hdata, __name)
+    (weechat_plugin->hdata_get_var_offset)(__hdata, __name)
 #define weechat_hdata_get_var_type(__hdata, __name)                     \
-    weechat_plugin->hdata_get_var_type(__hdata, __name)
+    (weechat_plugin->hdata_get_var_type)(__hdata, __name)
 #define weechat_hdata_get_var_type_string(__hdata, __name)              \
-    weechat_plugin->hdata_get_var_type_string(__hdata, __name)
+    (weechat_plugin->hdata_get_var_type_string)(__hdata, __name)
 #define weechat_hdata_get_var_array_size(__hdata, __pointer, __name)    \
-    weechat_plugin->hdata_get_var_array_size(__hdata, __pointer,        \
-                                             __name)
+    (weechat_plugin->hdata_get_var_array_size)(__hdata, __pointer,      \
+                                               __name)
 #define weechat_hdata_get_var_array_size_string(__hdata, __pointer,     \
                                                 __name)                 \
-    weechat_plugin->hdata_get_var_array_size_string(__hdata, __pointer, \
-                                                    __name)
+    (weechat_plugin->hdata_get_var_array_size_string)(__hdata,          \
+                                                      __pointer,        \
+                                                      __name)
 #define weechat_hdata_get_var_hdata(__hdata, __name)                    \
-    weechat_plugin->hdata_get_var_hdata(__hdata, __name)
+    (weechat_plugin->hdata_get_var_hdata)(__hdata, __name)
 #define weechat_hdata_get_var(__hdata, __pointer, __name)               \
-    weechat_plugin->hdata_get_var(__hdata, __pointer, __name)
+    (weechat_plugin->hdata_get_var)(__hdata, __pointer, __name)
 #define weechat_hdata_get_var_at_offset(__hdata, __pointer, __offset)   \
-    weechat_plugin->hdata_get_var_at_offset(__hdata, __pointer,         \
-                                            __offset)
+    (weechat_plugin->hdata_get_var_at_offset)(__hdata, __pointer,       \
+                                              __offset)
 #define weechat_hdata_get_list(__hdata, __name)                         \
-    weechat_plugin->hdata_get_list(__hdata, __name)
+    (weechat_plugin->hdata_get_list)(__hdata, __name)
 #define weechat_hdata_check_pointer(__hdata, __list, __pointer)         \
-    weechat_plugin->hdata_check_pointer(__hdata, __list, __pointer)
+    (weechat_plugin->hdata_check_pointer)(__hdata, __list, __pointer)
 #define weechat_hdata_move(__hdata, __pointer, __count)                 \
-    weechat_plugin->hdata_move(__hdata, __pointer, __count)
+    (weechat_plugin->hdata_move)(__hdata, __pointer, __count)
 #define weechat_hdata_search(__hdata, __pointer, __search, __move)      \
-    weechat_plugin->hdata_search(__hdata, __pointer, __search, __move)
+    (weechat_plugin->hdata_search)(__hdata, __pointer, __search,        \
+                                   __move)
 #define weechat_hdata_char(__hdata, __pointer, __name)                  \
-    weechat_plugin->hdata_char(__hdata, __pointer, __name)
+    (weechat_plugin->hdata_char)(__hdata, __pointer, __name)
 #define weechat_hdata_integer(__hdata, __pointer, __name)               \
-    weechat_plugin->hdata_integer(__hdata, __pointer, __name)
+    (weechat_plugin->hdata_integer)(__hdata, __pointer, __name)
 #define weechat_hdata_long(__hdata, __pointer, __name)                  \
-    weechat_plugin->hdata_long(__hdata, __pointer, __name)
+    (weechat_plugin->hdata_long)(__hdata, __pointer, __name)
 #define weechat_hdata_string(__hdata, __pointer, __name)                \
-    weechat_plugin->hdata_string(__hdata, __pointer, __name)
+    (weechat_plugin->hdata_string)(__hdata, __pointer, __name)
 #define weechat_hdata_pointer(__hdata, __pointer, __name)               \
-    weechat_plugin->hdata_pointer(__hdata, __pointer, __name)
+    (weechat_plugin->hdata_pointer)(__hdata, __pointer, __name)
 #define weechat_hdata_time(__hdata, __pointer, __name)                  \
-    weechat_plugin->hdata_time(__hdata, __pointer, __name)
+    (weechat_plugin->hdata_time)(__hdata, __pointer, __name)
 #define weechat_hdata_hashtable(__hdata, __pointer, __name)             \
-    weechat_plugin->hdata_hashtable(__hdata, __pointer, __name)
+    (weechat_plugin->hdata_hashtable)(__hdata, __pointer, __name)
 #define weechat_hdata_set(__hdata, __pointer, __name, __value)          \
-    weechat_plugin->hdata_set(__hdata, __pointer, __name, __value)
+    (weechat_plugin->hdata_set)(__hdata, __pointer, __name, __value)
 #define weechat_hdata_update(__hdata, __pointer, __hashtable)           \
-    weechat_plugin->hdata_update(__hdata, __pointer, __hashtable)
+    (weechat_plugin->hdata_update)(__hdata, __pointer, __hashtable)
 #define weechat_hdata_get_string(__hdata, __property)                   \
-    weechat_plugin->hdata_get_string(__hdata, __property)
+    (weechat_plugin->hdata_get_string)(__hdata, __property)
 
 /* upgrade */
 #define weechat_upgrade_new(__filename, __write)                        \
-    weechat_plugin->upgrade_new(__filename, __write)
+    (weechat_plugin->upgrade_new)(__filename, __write)
 #define weechat_upgrade_write_object(__upgrade_file, __object_id,       \
                                      __infolist)                        \
-    weechat_plugin->upgrade_write_object(__upgrade_file, __object_id,   \
-                                         __infolist)
+    (weechat_plugin->upgrade_write_object)(__upgrade_file, __object_id, \
+                                           __infolist)
 #define weechat_upgrade_read(__upgrade_file, __callback_read,           \
                              __callback_read_data)                      \
-    weechat_plugin->upgrade_read(__upgrade_file, __callback_read,       \
-                                 __callback_read_data)
+    (weechat_plugin->upgrade_read)(__upgrade_file, __callback_read,     \
+                                   __callback_read_data)
 #define weechat_upgrade_close(__upgrade_file)                           \
-    weechat_plugin->upgrade_close(__upgrade_file)
+    (weechat_plugin->upgrade_close)(__upgrade_file)
 
 #ifdef __cplusplus
 }
