# $NetBSD: buildlink3.mk,v 1.1 2004/02/01 10:01:08 jlam Exp $

.if !defined(MESA_BUILDLINK3_MK)
MESA_BUILDLINK3_MK=	defined

BUILDLINK_PREFIX.Mesa=	${BUILDLINK_PREFIX.MesaLib}

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"

.endif	# MESA_BUILDLINK3_MK
