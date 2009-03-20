# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:25:30 joerg Exp $

BUILDLINK_TREE+=	libxml

.if !defined(LIBXML_BUILDLINK3_MK)
LIBXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxml+=	libxml>=1.8.11
BUILDLINK_ABI_DEPENDS.libxml+=	libxml>=1.8.17nb3
BUILDLINK_FILES.libxml+=	include/gnome-xml/libxml/*.h
BUILDLINK_PKGSRCDIR.libxml?=	../../textproc/libxml

.include "../../devel/zlib/buildlink3.mk"
.endif # LIBXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxml
