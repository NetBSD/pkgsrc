# $NetBSD: hacks.mk,v 1.2 2019/11/24 01:04:20 gdt Exp $

.include "../../mk/compiler.mk"

.if ${PKGSRC_COMPILER:Mido}
CPPFLAGS+=	-DNO_ATTRIBUTE
.endif
