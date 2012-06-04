# $NetBSD: buildlink3.mk,v 1.12 2012/06/04 09:29:55 wiz Exp $

BUILDLINK_TREE+=	xmms-meta-input

.if !defined(XMMS_META_INPUT_BUILDLINK3_MK)
XMMS_META_INPUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmms-meta-input+=	xmms-meta-input>=0.4
BUILDLINK_ABI_DEPENDS.xmms-meta-input+=	xmms-meta-input>=0.4nb7
BUILDLINK_PKGSRCDIR.xmms-meta-input?=	../../audio/xmms-meta-input

.include "../../audio/xmms/buildlink3.mk"
.endif # XMMS_META_INPUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmms-meta-input
