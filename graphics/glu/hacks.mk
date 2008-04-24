# $NetBSD: hacks.mk,v 1.1 2008/04/24 07:40:24 bjs Exp $
#
.if !defined(GLU_HACKS_MK)
GLU_HACKS_MK=	# defined
.  include "../../graphics/MesaLib/hacks.mk"
.endif
