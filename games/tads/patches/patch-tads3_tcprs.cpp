$NetBSD: patch-tads3_tcprs.cpp,v 1.1 2013/01/10 23:56:32 joerg Exp $

--- tads3/tcprs.cpp.orig	2013-01-10 22:23:58.000000000 +0000
+++ tads3/tcprs.cpp
@@ -116,7 +116,7 @@ static const CTcPrsOpAnd S_op_and(&S_op_
 static const CTcPrsOpOr S_op_or(&S_op_and, &S_op_and);
 
 /* conditional operator */
-static const CTcPrsOpIf S_op_if;
+static CTcPrsOpIf S_op_if;
 
 /* 
  *   assignment operator - note that this is non-const, because we must be
