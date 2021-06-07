# $NetBSD: buildlink3.mk,v 1.16 2021/06/07 11:52:48 adam Exp $

BUILDLINK_TREE+=	hdf5

.if !defined(HDF5_BUILDLINK3_MK)
HDF5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hdf5+=	hdf5>=1.8.7
BUILDLINK_ABI_DEPENDS.hdf5+=	hdf5>=1.8.11
BUILDLINK_PKGSRCDIR.hdf5?=	../../devel/hdf5

pkgbase := hdf5
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.hdf5:Mszip}
.include "../../archivers/libaec/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.endif # HDF5_BUILDLINK3_MK

BUILDLINK_TREE+=	-hdf5
