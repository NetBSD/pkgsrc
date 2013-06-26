$NetBSD: patch-src_dar__suite_line__tools.cpp,v 1.1 2013/06/26 15:49:31 joerg Exp $

--- src/dar_suite/line_tools.cpp.orig	2013-06-20 19:14:58.000000000 +0000
+++ src/dar_suite/line_tools.cpp
@@ -215,8 +215,8 @@ void line_tools_repeat_param(const strin
 
     try
     {
-	deci x1 = tmp1;
-	deci x2 = tmp2;
+	libdar::deci x1 = tmp1;
+	libdar::deci x2 = tmp2;
 
 	repeat_count = x1.computer();
 	repeat_byte = x2.computer();
@@ -514,14 +514,14 @@ void line_tools_get_min_digits(string th
 	it1 = tools_find_first_char_of(the_arg, ',');
 	if(it1 == the_arg.end()) // a single number is provided
 	{
-	    deci tmp = the_arg;
+	    libdar::deci tmp = the_arg;
 	    num = tmp.computer();
 	}
 	else // at least two numbers are provided
 	{
 	    if(the_arg.begin() != it1)
 	    {
-		deci convert = string(the_arg.begin(), it1);
+		libdar::deci convert = string(the_arg.begin(), it1);
 		num = convert.computer();
 	    }
 		// else we ignore the leading ','
@@ -533,20 +533,20 @@ void line_tools_get_min_digits(string th
 	    it2 = tools_find_first_char_of(tmp2, ',');
 	    if(it2 == tmp2.end()) // just two number have been provided
 	    {
-		deci convert = tmp2;
+		libdar::deci convert = tmp2;
 		ref_num = convert.computer();
 	    }
 	    else
 	    {
 		if(tmp2.begin() != it2)
 		{
-		    deci convert = string(tmp2.begin(), it2);
+		    libdar::deci convert = string(tmp2.begin(), it2);
 		    ref_num = convert.computer();
 		}
 		++it2;
 		if(it2 != tmp2.end())
 		{
-		    deci convert = string(it2, tmp2.end());
+		    libdar::deci convert = string(it2, tmp2.end());
 		    aux_num = convert.computer();
 		}
 	    }
