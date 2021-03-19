# $NetBSD: buildlink3.mk,v 1.1 2021/03/19 22:17:02 markd Exp $

BUILDLINK_TREE+=	libkolabxml

.if !defined(LIBKOLABXML_BUILDLINK3_MK)
LIBKOLABXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkolabxml+=	libkolabxml>=1.1.6
BUILDLINK_PKGSRCDIR.libkolabxml?=	../../textproc/libkolabxml

.endif	# LIBKOLABXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkolabxml
