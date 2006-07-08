# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:38 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XMMS_META_INPUT_BUILDLINK3_MK:=	${XMMS_META_INPUT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xmms-meta-input
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxmms-meta-input}
BUILDLINK_PACKAGES+=	xmms-meta-input
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xmms-meta-input

.if !empty(XMMS_META_INPUT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xmms-meta-input+=	xmms-meta-input>=0.4
BUILDLINK_ABI_DEPENDS.xmms-meta-input?=	xmms-meta-input>=0.4nb2
BUILDLINK_PKGSRCDIR.xmms-meta-input?=	../../audio/xmms-meta-input
.endif	# XMMS_META_INPUT_BUILDLINK3_MK

.include "../../audio/xmms/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
