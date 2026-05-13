$NetBSD: patch-lib_utils_mu-sexp.cc,v 1.1 2026/05/13 19:12:43 ktnb Exp $

ctype(3) for NetBSD 11

--- lib/utils/mu-sexp.cc.orig	2026-04-27 19:03:29.000000000 +0000
+++ lib/utils/mu-sexp.cc
@@ -129,11 +129,11 @@ parse_symbol(const std::string& expr, size_t& pos)
 static Result<Sexp>
 parse_symbol(const std::string& expr, size_t& pos)
 {
-	if (!isalpha(expr[pos]) && expr[pos] != ':') // sanity check.
+	if (!isalpha(static_cast<unsigned char>(expr[pos])) && expr[pos] != ':') // sanity check.
 		return Err(parsing_error(pos, "expected: <alpha>|: but got '{}", expr[pos]));
 
 	std::string symb(1, expr[pos]);
-	for (++pos; isalnum(expr[pos]) || expr[pos] == '-'; ++pos)
+	for (++pos; isalnum(static_cast<unsigned char>(expr[pos])) || expr[pos] == '-'; ++pos)
 		symb += expr[pos];
 
 	return Ok(Sexp{Sexp::Symbol{symb}});
@@ -153,9 +153,9 @@ parse(const std::string& expr, size_t& pos)
 			return parse_list(expr, pos);
 		else if (kar == '"')
 			return parse_string(expr, pos);
-		else if (isdigit(kar) || kar == '-')
+		else if (isdigit(static_cast<unsigned char>(kar)) || kar == '-')
 			return parse_integer(expr, pos);
-		else if (isalpha(kar) || kar == ':')
+		else if (isalpha(static_cast<unsigned char>(kar)) || kar == ':')
 			return parse_symbol(expr, pos);
 		else
 			return Err(parsing_error(pos, "unexpected character '{}", kar));
