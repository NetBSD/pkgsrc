# $NetBSD: hacks.mk,v 1.1.2.2 2012/05/03 18:01:43 tron Exp $

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CFLAGS+=	-D__attribute__\(x\)=
.endif
