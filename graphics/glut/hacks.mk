# $NetBSD: hacks.mk,v 1.1 2008/04/24 07:40:24 bjs Exp $
#
.if !defined(GLUT_HACKS_MK)
GLUT_HACKS_MK=	# defined
.  include "../../graphics/MesaLib/hacks.mk"
.endif
