# $NetBSD: buildlink3.mk,v 1.4 2004/04/25 19:55:54 snj Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXML_BUILDLINK3_MK:=	${LIBXML_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxml
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxml}
BUILDLINK_PACKAGES+=	libxml

.if !empty(LIBXML_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libxml+=	libxml>=1.8.11
BUILDLINK_FILES.libxml+=	include/gnome-xml/libxml/*.h
BUILDLINK_PKGSRCDIR.libxml?=	../../textproc/libxml
.endif	# LIBXML_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
