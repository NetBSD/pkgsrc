# $NetBSD: buildlink3.mk,v 1.8 2008/01/18 05:06:37 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GDAL_LIB_BUILDLINK3_MK:=	${GDAL_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gdal-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngdal-lib}
BUILDLINK_PACKAGES+=	gdal-lib
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gdal-lib

.if !empty(GDAL_LIB_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gdal-lib+=	gdal-lib>=1.3.1
BUILDLINK_ABI_DEPENDS.gdal-lib?=	gdal-lib>=1.4.0nb3
BUILDLINK_PKGSRCDIR.gdal-lib?=	../../geography/gdal-lib
.endif	# GDAL_LIB_BUILDLINK3_MK

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

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
