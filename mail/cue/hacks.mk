# $NetBSD: hacks.mk,v 1.1 2009/12/15 13:11:18 taca Exp $

.include "../../mk/compiler.mk"

.if ${PKGSRC_COMPILER} == "ido"
CPPFLAGS+=	-DNO_ATTRIBUTE
.endif
