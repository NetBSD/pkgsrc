$NetBSD: patch-src_libdar_mask__list.hpp,v 1.3 2014/05/14 04:35:20 rodent Exp $

--- src/libdar/mask_list.hpp.orig	2014-04-21 10:02:16.000000000 +0000
+++ src/libdar/mask_list.hpp
@@ -70,46 +70,10 @@ namespace libdar
 
     private:
 
-	    // we need to change to lexicographical order relationship for the '/' character be the most lower of all. This way
-	    // the first entry listed from a set a file sharing the same first characters will be the one corresponding
-	    // to the directory with this common prefix.
-
-	class my_char
-	{
-	public:
- 	    const my_char & operator = (const char x) { val = x; return *this; };
-	  
-	    bool operator < (const my_char & x) const
-	    {
-		if(val == '/')
-		    if(x.val == '/')
-			return false;
-		    else
-			return true;
-		else
-		    if(x.val == '/')
-			return false;
-		    else
-			return val < x.val;
-	    };
-
-	    operator char() const
-	    {
-		return val;
-	    };
-
-	private:
-	    char val;
-	};
-
-        std::vector <std::basic_string<my_char> > contenu;
+        std::vector <std::string > contenu;
         U_I taille;
         bool case_s;
         bool including;   // mask is used for including files (not for excluding files)
-
-	static std::list<std::basic_string<my_char> > convert_list_string_char(const std::list<std::string> & src);
-	static std::basic_string<my_char> convert_string_char(const std::string & src);
-	static std::string convert_string_my_char(const std::basic_string<my_char> & src);
     };
 
         /// @}
