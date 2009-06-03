# $NetBSD: buildlink3.mk,v 1.11 2009/06/03 17:28:30 hasso Exp $

BUILDLINK_TREE+=	gdal-lib

.if !defined(GDAL_LIB_BUILDLINK3_MK)
GDAL_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdal-lib+=	gdal-lib>=1.6.1
BUILDLINK_ABI_DEPENDS.gdal-lib?=	gdal-lib>=1.6.1
BUILDLINK_PKGSRCDIR.gdal-lib?=	../../geography/gdal-lib

pkgbase := gdal-lib
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gdal-lib:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.gdal-lib:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # GDAL_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdal-lib
