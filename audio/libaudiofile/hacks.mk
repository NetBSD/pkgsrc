# $NetBSD: hacks.mk,v 1.1 2012/07/09 16:42:37 bsiegert Exp $

# gcc in MirBSD does not recognize these options
.if ${OPSYS} == "MirBSD"
BUILDLINK_TRANSFORM+=	rm:-fvisibility=hidden rm:-fvisibility-inlines-hidden
.endif
