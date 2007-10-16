# $NetBSD: hacks.mk,v 1.2 2007/10/16 23:49:00 tnn Exp $

.if !defined(OPENSP_HACKS_MK)
OPENSP_HACKS_MK=	# defined

### [Sat Feb 11 23:03:26 CET 2006 : schwarz]
### IRIX 5 needs to link with libgen to use dirname()
###
.if ${OPSYS} == "IRIX"
PKG_HACKS+=	add-lgen
LIBS+=		-lgen
.endif

.endif
