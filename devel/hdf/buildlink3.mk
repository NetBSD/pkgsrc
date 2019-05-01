# $NetBSD: buildlink3.mk,v 1.12 2019/05/01 12:36:09 bacon Exp $

BUILDLINK_TREE+=	hdf

.if !defined(HDF_BUILDLINK3_MK)
HDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hdf+=	hdf>=4.1r5
BUILDLINK_ABI_DEPENDS.hdf+=	hdf>=4.2r4nb2
BUILDLINK_PKGSRCDIR.hdf?=	../../devel/hdf
.endif # HDF_BUILDLINK3_MK

.include "../../archivers/libaec/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"

BUILDLINK_TREE+=	-hdf
