# $NetBSD: hacks.mk,v 1.1 2012/04/30 02:51:40 dholland Exp $

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CFLAGS+=	-D__attribute__\(x\)=
.endif
