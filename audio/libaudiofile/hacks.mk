# $NetBSD: hacks.mk,v 1.1.2.2 2012/07/10 22:55:51 tron Exp $

# gcc in MirBSD does not recognize these options
.if ${OPSYS} == "MirBSD"
BUILDLINK_TRANSFORM+=	rm:-fvisibility=hidden rm:-fvisibility-inlines-hidden
.endif
