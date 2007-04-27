# $NetBSD: hacks.mk,v 1.1 2007/04/27 22:31:53 schmonz Exp $

.include "../../mk/bsd.prefs.mk"

# Fix build on OS X with BIND9 system resolver
.if ${OPSYS} == "Darwin"
PKG_HACKS+=		macosx-bind9-bind8compat
CFLAGS+=		-DBIND_8_COMPAT=1
.endif
