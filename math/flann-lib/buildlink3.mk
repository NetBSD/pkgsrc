# $NetBSD: buildlink3.mk,v 1.5 2023/08/31 10:22:29 adam Exp $

BUILDLINK_TREE+=	flann-lib

.if !defined(FLANN_LIB_BUILDLINK3_MK)
FLANN_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flann-lib+=	flann-lib>=1.9.0
BUILDLINK_ABI_DEPENDS.flann-lib+=	flann-lib>=1.9.2nb1
BUILDLINK_PKGSRCDIR.flann-lib?=		../../math/flann-lib

.include "../../archivers/lz4/buildlink3.mk"
.include "../../devel/hdf5-c++/buildlink3.mk"

.endif # FLANN_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-flann-lib
