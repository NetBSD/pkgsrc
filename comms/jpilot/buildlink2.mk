# $NetBSD: buildlink2.mk,v 1.8 2004/01/03 18:49:36 reed Exp $

.if !defined(JPILOT_BUILDLINK2_MK)
JPILOT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		jpilot
BUILDLINK_DEPENDS.jpilot?=	jpilot>=0.99.5nb4
BUILDLINK_PKGSRCDIR.jpilot?=	../../comms/jpilot
BUILDLINK_DEPMETHOD.jpilot?=	build

EVAL_PREFIX+=			BUILDLINK_PREFIX.jpilot=jpilot
BUILDLINK_PREFIX.jpilot_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.jpilot=		include/jpilot/*

.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	jpilot-buildlink

jpilot-buildlink: _BUILDLINK_USE

.endif	# JPILOT_BUILDLINK2_MK
