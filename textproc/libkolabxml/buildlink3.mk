# $NetBSD: buildlink3.mk,v 1.5 2022/01/10 01:46:45 ryoon Exp $

BUILDLINK_TREE+=	libkolabxml

.if !defined(LIBKOLABXML_BUILDLINK3_MK)
LIBKOLABXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkolabxml+=	libkolabxml>=1.1.6
BUILDLINK_ABI_DEPENDS.libkolabxml?=	libkolabxml>=1.1.6nb5
BUILDLINK_PKGSRCDIR.libkolabxml?=	../../textproc/libkolabxml

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# LIBKOLABXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkolabxml
