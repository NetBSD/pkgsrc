# $NetBSD: buildlink3.mk,v 1.1 2004/03/12 02:55:49 snj Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XMMS_META_INPUT_BUILDLINK3_MK:=	${XMMS_META_INPUT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xmms-meta-input
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxmms-meta-input}
BUILDLINK_PACKAGES+=	xmms-meta-input

.if !empty(XMMS_META_INPUT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xmms-meta-input+=	xmms-meta-input>=0.4
BUILDLINK_PKGSRCDIR.xmms-meta-input?=	../../audio/xmms-meta-input

.include "../../audio/xmms/buildlink3.mk"

.endif	# XMMS_META_INPUT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
