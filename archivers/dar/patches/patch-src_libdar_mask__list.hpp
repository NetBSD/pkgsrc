$NetBSD: patch-src_libdar_mask__list.hpp,v 1.1 2013/06/26 15:49:31 joerg Exp $

--- src/libdar/mask_list.hpp.orig	2013-06-20 19:11:02.000000000 +0000
+++ src/libdar/mask_list.hpp
@@ -80,7 +80,7 @@ namespace libdar
 	class my_char
 	{
 	public:
-	    my_char() { val = 0; };
+	    my_char() = default;
 	    my_char(const char x) : val(x) {};
 	    bool operator < (const my_char & x) const
 	    {
