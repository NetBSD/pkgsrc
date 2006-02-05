# $NetBSD: buildlink3.mk,v 1.3 2006/02/05 23:08:18 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XMMS_META_INPUT_BUILDLINK3_MK:=	${XMMS_META_INPUT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xmms-meta-input
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxmms-meta-input}
BUILDLINK_PACKAGES+=	xmms-meta-input

.if !empty(XMMS_META_INPUT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xmms-meta-input+=	xmms-meta-input>=0.4
BUILDLINK_RECOMMENDED.xmms-meta-input?=	xmms-meta-input>=0.4nb2
BUILDLINK_PKGSRCDIR.xmms-meta-input?=	../../audio/xmms-meta-input
.endif	# XMMS_META_INPUT_BUILDLINK3_MK

.include "../../audio/xmms/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
