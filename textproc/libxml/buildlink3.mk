# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:40 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXML_BUILDLINK3_MK:=	${LIBXML_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxml
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxml}
BUILDLINK_PACKAGES+=	libxml

.if !empty(LIBXML_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libxml+=	libxml>=1.8.11
BUILDLINK_PKGSRCDIR.libxml?=	../../textproc/libxml

.include "../../devel/zlib/buildlink3.mk"

.endif	# LIBXML_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
