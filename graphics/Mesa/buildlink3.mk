# $NetBSD: buildlink3.mk,v 1.2 2004/02/11 02:03:41 jlam Exp $

.if !defined(MESA_BUILDLINK3_MK)
MESA_BUILDLINK3_MK=	defined

BUILDLINK_PREFIX.Mesa=	${BUILDLINK_PREFIX.MesaLib}

# The ordering is important here as glut/buildlink3.mk sets the version
# of Mesa required.
#
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"

.endif	# MESA_BUILDLINK3_MK
