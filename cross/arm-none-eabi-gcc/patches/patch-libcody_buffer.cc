$NetBSD: patch-libcody_buffer.cc,v 1.1 2026/04/20 03:49:24 js Exp $

--- libcody/buffer.cc.orig	2026-04-20 01:24:57.046758295 +0000
+++ libcody/buffer.cc
@@ -30,7 +30,7 @@
 namespace Cody {
 namespace Detail {
 
-static const char CONTINUE = S2C(u8";");
+static const char CONTINUE = S2C(";");
 
 void MessageBuffer::BeginLine ()
 {
@@ -38,9 +38,9 @@ void MessageBuffer::BeginLine ()
     {
       // Terminate the previous line with a continuation
       buffer.reserve (buffer.size () + 3);
-      buffer.push_back (S2C(u8" "));
+      buffer.push_back (S2C(" "));
       buffer.push_back (CONTINUE);
-      buffer.push_back (S2C(u8"\n"));
+      buffer.push_back (S2C("\n"));
     }
   lastBol = buffer.size ();
 }
@@ -65,11 +65,11 @@ void MessageBuffer::Append (char const *
       for (size_t ix = len; ix--;)
 	{
 	  unsigned char c = (unsigned char)str[ix];
-	  if (!((c >= S2C(u8"a") && c <= S2C(u8"z"))
-		|| (c >= S2C(u8"A") && c <= S2C(u8"Z"))
-		|| (c >= S2C(u8"0") && c <= S2C(u8"9"))
-		|| c == S2C(u8"-") || c == S2C(u8"+") || c == S2C(u8"_")
-		|| c == S2C(u8"/") || c == S2C(u8"%") || c == S2C(u8".")))
+	  if (!((c >= S2C("a") && c <= S2C("z"))
+		|| (c >= S2C("A") && c <= S2C("Z"))
+		|| (c >= S2C("0") && c <= S2C("9"))
+		|| c == S2C("-") || c == S2C("+") || c == S2C("_")
+		|| c == S2C("/") || c == S2C("%") || c == S2C(".")))
 	    {
 	      quote = true;
 	      break;
@@ -81,7 +81,7 @@ void MessageBuffer::Append (char const *
   buffer.reserve (buffer.size () + len * (quote ? 3 : 1) + 2);
 
   if (quote)
-    buffer.push_back (S2C(u8"'"));
+    buffer.push_back (S2C("'"));
 
   for (auto *end = str + len; str != end;)
     {
@@ -93,8 +93,8 @@ void MessageBuffer::Append (char const *
 	for (e = str; e != end; ++e)
 	  {
 	    unsigned char c = (unsigned char)*e;
-	    if (c < S2C(u8" ") || c == 0x7f
-		|| c == S2C(u8"\\") || c == S2C(u8"'"))
+	    if (c < S2C(" ") || c == 0x7f
+		|| c == S2C("\\") || c == S2C("'"))
 	      break;
 	  }
       buffer.insert (buffer.end (), str, e);
@@ -103,19 +103,19 @@ void MessageBuffer::Append (char const *
       if (str == end)
 	break;
 
-      buffer.push_back (S2C(u8"\\"));
+      buffer.push_back (S2C("\\"));
       switch (unsigned char c = (unsigned char)*str++)
 	{
-	case S2C(u8"\t"):
-	  c = S2C(u8"t");
+	case S2C("\t"):
+	  c = S2C("t");
 	  goto append;
 
-	case S2C(u8"\n"):
-	  c = S2C(u8"n");
+	case S2C("\n"):
+	  c = S2C("n");
 	  goto append;
 
-	case S2C(u8"'"):
-	case S2C(u8"\\"):
+	case S2C("'"):
+	case S2C("\\"):
 	append:
 	  buffer.push_back (c);
 	  break;
@@ -127,16 +127,16 @@ void MessageBuffer::Append (char const *
 	      shift -= 4;
 
 	      char nibble = (c >> shift) & 0xf;
-	      nibble += S2C(u8"0");
-	      if (nibble > S2C(u8"9"))
-		nibble += S2C(u8"a") - (S2C(u8"9") + 1);
+	      nibble += S2C("0");
+	      if (nibble > S2C("9"))
+		nibble += S2C("a") - (S2C("9") + 1);
 	      buffer.push_back (nibble);
 	    }
 	}
     }
 
   if (quote)
-    buffer.push_back (S2C(u8"'"));
+    buffer.push_back (S2C("'"));
 }
 
 void MessageBuffer::Append (char c)
@@ -205,7 +205,7 @@ int MessageBuffer::Read (int fd) noexcep
   bool more = true;
   for (;;)
     {
-      auto newline = std::find (iter, buffer.end (), S2C(u8"\n"));
+      auto newline = std::find (iter, buffer.end (), S2C("\n"));
       if (newline == buffer.end ())
 	break;
       more = newline != buffer.begin () && newline[-1] == CONTINUE;
@@ -233,7 +233,7 @@ int MessageBuffer::Lex (std::vector<std:
   if (IsAtEnd ())
     return ENOENT;
 
-  Assert (buffer.back () == S2C(u8"\n"));
+  Assert (buffer.back () == S2C("\n"));
 
   auto iter = buffer.begin () + lastBol;
 
@@ -242,25 +242,25 @@ int MessageBuffer::Lex (std::vector<std:
       char c = *iter;
 
       ++iter;
-      if (c == S2C(u8" ") || c == S2C(u8"\t"))
+      if (c == S2C(" ") || c == S2C("\t"))
 	{
 	  word = nullptr;
 	  continue;
 	}
 
-      if (c == S2C(u8"\n"))
+      if (c == S2C("\n"))
 	break;
 
       if (c == CONTINUE)
 	{
 	  // Line continuation
-	  if (word || *iter != S2C(u8"\n"))
+	  if (word || *iter != S2C("\n"))
 	    goto malformed;
 	  ++iter;
 	  break;
 	}
 
-      if (c <= S2C(u8" ") || c >= 0x7f)
+      if (c <= S2C(" ") || c >= 0x7f)
 	goto malformed;
 
       if (!word)
@@ -269,20 +269,20 @@ int MessageBuffer::Lex (std::vector<std:
 	  word = &result.back ();
 	}
 
-      if (c == S2C(u8"'"))
+      if (c == S2C("'"))
 	{
 	  // Quoted word
 	  for (;;)
 	    {
 	      c = *iter;
 
-	      if (c == S2C(u8"\n"))
+	      if (c == S2C("\n"))
 		{
 		malformed:;
 		  result.clear ();
-		  iter = std::find (iter, buffer.end (), S2C(u8"\n"));
+		  iter = std::find (iter, buffer.end (), S2C("\n"));
 		  auto back = iter;
-		  if (back[-1] == CONTINUE  && back[-2] == S2C(u8" "))
+		  if (back[-1] == CONTINUE  && back[-2] == S2C(" "))
 		    // Smells like a line continuation
 		    back -= 2;
 		  result.emplace_back (&buffer[lastBol],
@@ -292,35 +292,35 @@ int MessageBuffer::Lex (std::vector<std:
 		  return EINVAL;
 		}
 
-	      if (c < S2C(u8" ") || c >= 0x7f)
+	      if (c < S2C(" ") || c >= 0x7f)
 		goto malformed;
 
 	      ++iter;
-	      if (c == S2C(u8"'"))
+	      if (c == S2C("'"))
 		break;
 
-	      if (c == S2C(u8"\\"))
+	      if (c == S2C("\\"))
 		// escape
 		switch (c = *iter)
 		  {
-		    case S2C(u8"\\"):
-		    case S2C(u8"'"):
+		    case S2C("\\"):
+		    case S2C("'"):
 		      ++iter;
 		      break;
 
-		    case S2C(u8"n"):
-		      c = S2C(u8"\n");
+		    case S2C("n"):
+		      c = S2C("\n");
 		      ++iter;
 		      break;
 
-		    case S2C(u8"_"):
+		    case S2C("_"):
 		      // We used to escape SPACE as \_, so accept that
-		      c = S2C(u8" ");
+		      c = S2C(" ");
 		      ++iter;
 		      break;
 
-		    case S2C(u8"t"):
-		      c = S2C(u8"\t");
+		    case S2C("t"):
+		      c = S2C("\t");
 		      ++iter;
 		      break;
 
@@ -330,22 +330,22 @@ int MessageBuffer::Lex (std::vector<std:
 			for (unsigned nibble = 0; nibble != 2; nibble++)
 			  {
 			    c = *iter;
-			    if (c < S2C(u8"0"))
+			    if (c < S2C("0"))
 			      {
 				if (!nibble)
 				  goto malformed;
 				break;
 			      }
-			    else if (c <= S2C(u8"9"))
-			      c -= S2C(u8"0");
-			    else if (c < S2C(u8"a"))
+			    else if (c <= S2C("9"))
+			      c -= S2C("0");
+			    else if (c < S2C("a"))
 			      {
 				if (!nibble)
 				  goto malformed;
 				break;
 			      }
-			    else if (c <= S2C(u8"f"))
-			      c -= S2C(u8"a") - 10;
+			    else if (c <= S2C("f"))
+			      c -= S2C("a") - 10;
 			    else
 			      {
 				if (!nibble)
@@ -378,11 +378,11 @@ void MessageBuffer::LexedLine (std::stri
     {
       size_t pos = lastBol - 1;
       for (; pos; pos--)
-	if (buffer[pos-1] == S2C(u8"\n"))
+	if (buffer[pos-1] == S2C("\n"))
 	  break;
 
       size_t end = lastBol - 1;
-      if (buffer[end-1] == CONTINUE && buffer[end-2] == S2C(u8" "))
+      if (buffer[end-1] == CONTINUE && buffer[end-2] == S2C(" "))
 	// Strip line continuation
 	end -= 2;
       str.append (&buffer[pos], end - pos);
