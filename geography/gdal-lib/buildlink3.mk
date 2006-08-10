# $NetBSD: buildlink3.mk,v 1.5 2006/08/10 00:38:25 wiz Exp $

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
BUILDLINK_PKGSRCDIR.gdal-lib?=	../../geography/gdal-lib
.endif	# GDAL_LIB_BUILDLINK3_MK

.if !defined(PKG_BUILD_OPTIONS.gdal-lib)
PKG_BUILD_OPTIONS.gdal-lib!=                                             \
	cd ${BUILDLINK_PKGSRCDIR.gdal-lib} &&                            \
	${MAKE} show-var ${MAKEFLAGS} VARNAME=PKG_OPTIONS
MAKEFLAGS+=	PKG_BUILD_OPTIONS.gdal-lib=${PKG_BUILD_OPTIONS.gdal-lib:Q}
.endif
MAKEVARS+=	PKG_BUILD_OPTIONS.gdal-lib

.if !empty(PKG_BUILD_OPTIONS.gdal-lib:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
