# $NetBSD: buildlink3.mk,v 1.30 2024/11/07 13:34:45 gdt Exp $

BUILDLINK_TREE+=	pdal-lib

.if !defined(PDAL_LIB_BUILDLINK3_MK)
PDAL_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pdal-lib+=	pdal-lib>=2.1.0
BUILDLINK_ABI_DEPENDS.pdal-lib+=	pdal-lib>=2.7.1nb10
BUILDLINK_PKGSRCDIR.pdal-lib?=		../../geography/pdal-lib

.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../devel/hdf5-c++/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../geography/libgeotiff/buildlink3.mk"
.include "../../geography/laszip/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.endif # PDAL_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pdal-lib
