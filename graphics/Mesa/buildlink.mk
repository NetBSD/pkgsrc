# $NetBSD: buildlink.mk,v 1.9 2002/06/26 05:36:29 jlam Exp $
#
# This Makefile fragment is included by packages that use Mesa.
#
# To use this Makefile fragment, simply:
#
# (1) Include this Makefile fragment in the package Makefile,
# (2) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (3) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(MESA_BUILDLINK_MK)
MESA_BUILDLINK_MK=	# defined

BUILDLINK_PREFIX.Mesa=	${BUILDLINK_PREFIX.MesaLib}

.include "../../graphics/MesaLib/buildlink.mk"
.include "../../graphics/glu/buildlink.mk"
.include "../../graphics/glut/buildlink.mk"

.endif	# MESA_BUILDLINK_MK
