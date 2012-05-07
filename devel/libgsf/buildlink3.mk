# $NetBSD: buildlink3.mk,v 1.25 2012/05/07 01:53:24 dholland Exp $

BUILDLINK_TREE+=	libgsf

.if !defined(LIBGSF_BUILDLINK3_MK)
LIBGSF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgsf+=	libgsf>=1.13.3
BUILDLINK_ABI_DEPENDS.libgsf+=	libgsf>=1.14.22nb2
BUILDLINK_PKGSRCDIR.libgsf?=	../../devel/libgsf

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBGSF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgsf
