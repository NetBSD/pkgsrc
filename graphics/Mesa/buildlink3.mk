# $NetBSD: buildlink3.mk,v 1.4 2004/03/15 16:34:24 jlam Exp $

.if !defined(MESA_BUILDLINK3_MK)
MESA_BUILDLINK3_MK=	defined

BUILDLINK_PREFIX.Mesa=	${BUILDLINK_PREFIX.MesaLib}

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"

.endif	# MESA_BUILDLINK3_MK
