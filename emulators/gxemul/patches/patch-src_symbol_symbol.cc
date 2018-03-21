$NetBSD: patch-src_symbol_symbol.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/symbol/symbol.cc.orig	2014-08-17 08:45:15.000000000 +0000
+++ src/symbol/symbol.cc
@@ -133,7 +133,7 @@ char *get_symbol_name_and_n_args(struct 
 					    "%s", s->name);
 				else
 					snprintf(symbol_buf, SYMBOLBUF_MAX,
-					    "%s+0x%"PRIx64, s->name, (uint64_t)
+					    "%s+0x%" PRIx64, s->name, (uint64_t)
 					    (addr - s->addr));
 				if (offset != NULL)
 					*offset = addr - s->addr;
@@ -157,7 +157,7 @@ char *get_symbol_name_and_n_args(struct 
 					    "%s", s->name);
 				else
 					snprintf(symbol_buf, SYMBOLBUF_MAX,
-					    "%s+0x%"PRIx64, s->name, (uint64_t)
+					    "%s+0x%" PRIx64, s->name, (uint64_t)
 					    (addr - s->addr));
 
 				if (offset != NULL)
@@ -318,7 +318,7 @@ void symbol_readfile(struct symbol_conte
 		addr = strtoull(b1, NULL, 16);
 		len  = strtoull(b2, NULL, 16);
 		type = b3[0];
-		/*  printf("addr=%016"PRIx64" len=%016"PRIx64" type=%i\n",
+		/*  printf("addr=%016" PRIx64 " len=%016" PRIx64 " type=%i\n",
 		    addr, len, type);  */
 
 		if (type == 't' || type == 'r' || type == 'g')
@@ -418,4 +418,3 @@ void symbol_init(struct symbol_context *
 	sc->sorted_array = 0;
 	sc->n_symbols = 0;
 }
-
