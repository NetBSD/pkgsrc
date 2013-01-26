# $NetBSD: buildlink3.mk,v 1.11 2013/01/26 21:36:19 adam Exp $

BUILDLINK_TREE+=	hdf

.if !defined(HDF_BUILDLINK3_MK)
HDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hdf+=	hdf>=4.1r5
BUILDLINK_ABI_DEPENDS.hdf+=	hdf>=4.2r4nb2
BUILDLINK_PKGSRCDIR.hdf?=	../../devel/hdf
.endif # HDF_BUILDLINK3_MK

.include "../../archivers/szip/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"

BUILDLINK_TREE+=	-hdf
