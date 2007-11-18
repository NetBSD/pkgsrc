# $NetBSD: hacks.mk,v 1.1 2007/11/18 00:37:05 adrianp Exp $

.include "../../mk/bsd.prefs.mk"

# Fix build on OS X with BIND9 system resolver
.if ${OPSYS} == "Darwin"
PKG_HACKS+=		macosx-bind9-bind8compat
CFLAGS+=		-DBIND_8_COMPAT=1
.endif
