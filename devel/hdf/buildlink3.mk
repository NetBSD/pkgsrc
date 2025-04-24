# $NetBSD: buildlink3.mk,v 1.14 2025/04/24 14:13:30 wiz Exp $

BUILDLINK_TREE+=	hdf

.if !defined(HDF_BUILDLINK3_MK)
HDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hdf+=	hdf>=4.1r5
BUILDLINK_ABI_DEPENDS.hdf+=	hdf>=4.2.15nb1
BUILDLINK_PKGSRCDIR.hdf?=	../../devel/hdf
.endif # HDF_BUILDLINK3_MK

.include "../../archivers/libaec/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"

BUILDLINK_TREE+=	-hdf
