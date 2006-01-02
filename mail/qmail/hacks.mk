# $NetBSD: hacks.mk,v 1.1 2006/01/02 21:13:43 schmonz Exp $

.include "../../mk/bsd.prefs.mk"

# Fix build on OS X with BIND9 system resolver
.if ${OPSYS} == "Darwin"
PKG_HACKS+=		macosx-bind9-bind8compat
CFLAGS+=		-DBIND_8_COMPAT=1
.endif
