# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:39 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SYNCE_LIBSYNCE_BUILDLINK3_MK:=	${SYNCE_LIBSYNCE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	synce-libsynce
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsynce-libsynce}
BUILDLINK_PACKAGES+=	synce-libsynce
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}synce-libsynce

.if !empty(SYNCE_LIBSYNCE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.synce-libsynce+=	synce-libsynce>=0.9.1
BUILDLINK_PKGSRCDIR.synce-libsynce?=	../../comms/synce-libsynce
.endif	# SYNCE_LIBSYNCE_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
