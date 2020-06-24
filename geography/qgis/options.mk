# $NetBSD: options.mk,v 1.18 2020/06/24 21:49:20 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qgis
PKG_SUPPORTED_OPTIONS=	python
# \todo After 2020Q2, drop python option (making it on).  Python
# within qgis is so huge that it is hard to imagine someone wanting to
# build qgis without python, and the cost of that theoretical person
# putting up with a few more bits is smaller than the maintenance pain
# of having an option.
PKG_SUGGESTED_OPTIONS+=	python

.include "../../mk/bsd.options.mk"

# \todo Flip sense of option (if it isn't just removed).
.if empty(PKG_OPTIONS:Mpython)
CMAKE_ARGS+=		-DWITH_BINDINGS:BOOL=FALSE
PYTHON_FOR_BUILD_ONLY=	YES
.include "../../lang/python/application.mk"
.else
CMAKE_ARGS+=		-DWITH_BINDINGS:BOOL=TRUE
CMAKE_ARGS+=		-DSIP_BINARY_PATH:PATH=${BUILDLINK_PREFIX.py-sip}/bin
CMAKE_ARGS+=		-DWITH_INTERNAL_MARKUPSAFE=FALSE
PLIST_SRC+=             ${PKGDIR}/PLIST.python
.include "../../lang/python/application.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-qt5/buildlink3.mk"
.include "../../x11/py-qt5-qscintilla/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-psycopg2-[0-9]*:../../databases/py-psycopg2
DEPENDS+=	${PYPKGPREFIX}-gdal-[0-9]*:../../geography/py-gdal
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe
.endif
