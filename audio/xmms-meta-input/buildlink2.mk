# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/24 00:09:55 ben Exp $
#

.if !defined(XMMS_META_INPUT_BUILDLINK2_MK)
XMMS_META_INPUT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		xmms-meta-input
BUILDLINK_DEPENDS.xmms-meta-input?=	xmms-meta-input>=0.4
BUILDLINK_PKGSRCDIR.xmms-meta-input?=	../../audio/xmms-meta-input/

EVAL_PREFIX+=	BUILDLINK_PREFIX.xmms-meta-input=xmms-meta-input
BUILDLINK_PREFIX.xmms-meta-input_DEFAULT=	${LOCALBASE}

BUILDLINK_TARGETS+=	xmms-meta-input-buildlink

xmms-meta-input-buildlink: _BUILDLINK_USE

.endif	# XMMS_META_INPUT_BUILDLINK2_MK
