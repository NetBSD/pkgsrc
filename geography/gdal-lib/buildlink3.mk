# $NetBSD: buildlink3.mk,v 1.86 2024/05/16 06:14:58 wiz Exp $

BUILDLINK_TREE+=	gdal-lib

.if !defined(GDAL_LIB_BUILDLINK3_MK)
GDAL_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdal-lib+=	gdal-lib>=3.0.0
BUILDLINK_ABI_DEPENDS.gdal-lib+=	gdal-lib>=3.5.3nb9
BUILDLINK_PKGSRCDIR.gdal-lib?=		../../geography/gdal-lib

pkgbase := gdal-lib
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.gdal-lib:Mpgsql}
.include "../../mk/pgsql.buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.gdal-lib:Mmysql}
.include "../../mk/mysql.buildlink3.mk"
.endif

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../math/qhull/buildlink3.mk"
.include "../../geography/libgeotiff/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # GDAL_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdal-lib
