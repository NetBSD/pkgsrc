# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:38:55 jlam Exp $

.if !defined(MESA_BUILDLINK2_MK)
MESA_BUILDLINK2_MK=	# defined

BUILDLINK_PREFIX.Mesa=	${BUILDLINK_PREFIX.MesaLib}

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"

.endif	# MESA_BUILDLINK2_MK
