# $NetBSD: buildlink2.mk,v 1.6 2004/03/26 02:27:54 wiz Exp $

.if !defined(GKRELLM_BUILDLINK2_MK)
GKRELLM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gkrellm
BUILDLINK_DEPENDS.gkrellm?=		gkrellm>=2.1.22
BUILDLINK_RECOMMENDED.gkrellm?=		gkrellm>=2.1.27nb2
BUILDLINK_PKGSRCDIR.gkrellm?=		../../sysutils/gkrellm

EVAL_PREFIX+=	BUILDLINK_PREFIX.gkrellm=gkrellm
BUILDLINK_PREFIX.gkrellm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gkrellm+=	include/gkrellm2/gkrellm.h
BUILDLINK_FILES.gkrellm+=	include/gkrellm2/gkrellm-public-proto.h

PTHREAD_OPTS+=		require

.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	gkrellm-buildlink

gkrellm-buildlink: _BUILDLINK_USE

.endif	# GKRELLM2_BUILDLINK2_MK
