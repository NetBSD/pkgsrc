# $NetBSD: buildlink2.mk,v 1.3 2003/07/13 13:53:15 wiz Exp $
#

.if !defined(GKRELLM_BUILDLINK2_MK)
GKRELLM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gkrellm
BUILDLINK_DEPENDS.gkrellm?=		gkrellm>=1.2.13nb2
BUILDLINK_PKGSRCDIR.gkrellm?=		../../sysutils/gkrellm

EVAL_PREFIX+=	BUILDLINK_PREFIX.gkrellm=gkrellm
BUILDLINK_PREFIX.gkrellm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gkrellm+=	include/gkrellm/gkrellm.h
BUILDLINK_FILES.gkrellm+=	include/gkrellm/gkrellm_public_proto.h

.include "../../graphics/imlib/buildlink2.mk"

BUILDLINK_TARGETS+=	gkrellm-buildlink

gkrellm-buildlink: _BUILDLINK_USE

.endif	# GKRELLM_BUILDLINK2_MK
