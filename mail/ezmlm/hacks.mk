# $NetBSD: hacks.mk,v 1.1 2005/01/08 17:54:34 schmonz Exp $

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-*)
PKG_HACKS+=		builtin-log
CFLAGS+=		-fno-builtin-log
.endif
