# $NetBSD: buildlink2.mk,v 1.3 2002/11/18 07:49:24 jlam Exp $

.if !defined(MESA_BUILDLINK2_MK)
MESA_BUILDLINK2_MK=	# defined

MESA_REQD?=		3.4.2
BUILDLINK_PREFIX.Mesa=	${BUILDLINK_PREFIX.MesaLib}

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"

.endif	# MESA_BUILDLINK2_MK
