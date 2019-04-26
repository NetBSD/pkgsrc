# $NetBSD: options.mk,v 1.11 2019/04/26 13:13:59 maya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qgis
PKG_SUPPORTED_OPTIONS=	python
# Don't enable python by default because it is not
# supported by gdal-lib and as a result we get a
# warning when qgis is launched.
# XXX fix gdal-lib and reenable this.
PKG_SUGGESTED_OPTIONS+= python

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Mpython)
CMAKE_ARGS+=		-DWITH_BINDINGS:BOOL=FALSE
PYTHON_FOR_BUILD_ONLY=	YES
.include "../../lang/python/application.mk"
.else
CMAKE_ARGS+=		-DWITH_BINDINGS:BOOL=TRUE
CMAKE_ARGS+=		-DSIP_BINARY_PATH:PATH=${BUILDLINK_PREFIX.py-sip}/bin
CMAKE_ARGS+=		-DWITH_INTERNAL_MARKUPSAFE=FALSE
PLIST_SRC+=             ${PKGDIR}/PLIST.python
#PYTHON_VERSIONS_INCOMPATIBLE=	 36 # ?not yet ported as of ?
.include "../../lang/python/application.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/py-qt4-qscintilla/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-psycopg2-[0-9]*:../../databases/py-psycopg2
DEPENDS+=	${PYPKGPREFIX}-gdal-[0-9]*:../../geography/py-gdal
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe
.endif
