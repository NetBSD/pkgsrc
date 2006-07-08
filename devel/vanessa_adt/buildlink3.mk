# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:48 jlam Exp $
#
# This file was created automatically using createbuildlink-3.5.

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
VANESSA_ADT_BUILDLINK3_MK:=	${VANESSA_ADT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	vanessa_adt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nvanessa_adt}
BUILDLINK_PACKAGES+=	vanessa_adt
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}vanessa_adt

.if !empty(VANESSA_ADT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.vanessa_adt+=	vanessa_adt>=0.0.6
BUILDLINK_ABI_DEPENDS.vanessa_adt+=	vanessa_adt>=0.0.6nb1
BUILDLINK_PKGSRCDIR.vanessa_adt?=	../../devel/vanessa_adt
.endif	# VANESSA_ADT_BUILDLINK3_MK

.include "../../devel/vanessa_logger/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
