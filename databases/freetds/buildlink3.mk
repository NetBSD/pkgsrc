# $NetBSD: buildlink3.mk,v 1.5 2005/12/27 21:04:23 reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FREETDS_BUILDLINK3_MK:=	${FREETDS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	freetds
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nfreetds}
BUILDLINK_PACKAGES+=	freetds

.if !empty(FREETDS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.freetds+=	freetds>=0.63nb2
BUILDLINK_PKGSRCDIR.freetds?=	../../databases/freetds
.endif	# FREETDS_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
