# $NetBSD: buildlink2.mk,v 1.2 2003/05/02 11:55:07 wiz Exp $
#
# This Makefile fragment is included by packages that use 3DKit.
#
# This file was created automatically using createbuildlink 2.1.
#

.if !defined(3DKIT_BUILDLINK2_MK)
3DKIT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			3DKit
BUILDLINK_DEPENDS.3DKit?=		3DKit>=0.3.1r2nb1
BUILDLINK_PKGSRCDIR.3DKit?=		../../graphics/3DKit

EVAL_PREFIX+=	BUILDLINK_PREFIX.3DKit=3DKit
BUILDLINK_PREFIX.3DKit_DEFAULT=	${LOCALBASE}

.include "../../graphics/GlutKit/buildlink2.mk"
.include "../../graphics/GLXKit/buildlink2.mk"
.include "../../graphics/SDLKit/buildlink2.mk"

BUILDLINK_TARGETS+=	3DKit-buildlink

3DKit-buildlink: _BUILDLINK_USE

.endif	# 3DKIT_BUILDLINK2_MK
