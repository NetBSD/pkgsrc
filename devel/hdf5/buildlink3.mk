# $NetBSD: buildlink3.mk,v 1.12 2009/03/20 19:24:15 joerg Exp $

BUILDLINK_TREE+=	hdf5

.if !defined(HDF5_BUILDLINK3_MK)
HDF5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hdf5+=	hdf5>=1.6.2
BUILDLINK_ABI_DEPENDS.hdf5+=	hdf5>=1.6.5nb1
BUILDLINK_PKGSRCDIR.hdf5?=	../../devel/hdf5

pkgbase := hdf5
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.hdf5:Mszip)
.include "../../archivers/szip/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.endif # HDF5_BUILDLINK3_MK

BUILDLINK_TREE+=	-hdf5
