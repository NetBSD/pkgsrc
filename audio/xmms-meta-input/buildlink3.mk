# $NetBSD: buildlink3.mk,v 1.13 2015/04/25 14:20:25 tnn Exp $

BUILDLINK_TREE+=	xmms-meta-input

.if !defined(XMMS_META_INPUT_BUILDLINK3_MK)
XMMS_META_INPUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmms-meta-input+=	xmms-meta-input>=0.4
BUILDLINK_ABI_DEPENDS.xmms-meta-input+=	xmms-meta-input>=0.4nb8
BUILDLINK_PKGSRCDIR.xmms-meta-input?=	../../audio/xmms-meta-input

.include "../../audio/xmms/buildlink3.mk"
.endif # XMMS_META_INPUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmms-meta-input
