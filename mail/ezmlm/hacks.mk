# $NetBSD: hacks.mk,v 1.2 2025/06/01 21:08:36 schmonz Exp $

.include "../../mk/compiler.mk"

.if ${CC_VERSION:Mgcc-*}
PKG_HACKS+=		builtin-log
CFLAGS+=		-fno-builtin-log
.endif
