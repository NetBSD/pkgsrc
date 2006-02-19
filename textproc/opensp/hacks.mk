# $NetBSD: hacks.mk,v 1.1 2006/02/19 18:32:27 schwarz Exp $

.if !defined(OPENSP_HACKS_MK)
OPENSP_HACKS_MK=	# defined

### [Sat Feb 11 23:03:26 CET 2006 : schwarz]
### IRIX 5 needs to link with libgen to use dirname()
###
.if !empty(LOWER_OPSYS:Mirix5*)
PKG_HACKS+=	add-lgen
LIBS+=		-lgen
.endif

.endif
