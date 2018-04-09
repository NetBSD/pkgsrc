# $NetBSD: options.mk,v 1.4 2018/04/09 08:47:35 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnucash
PKG_SUPPORTED_OPTIONS=	libdbi libofx python
PKG_SUGGESTED_OPTIONS=	libdbi libofx python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibofx)
CMAKE_ARGS+=	-DWITH_OFX=ON
PLIST_SRC+=	PLIST.ofx
.include "../../finance/libofx/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_OFX=OFF
.endif

.if !empty(PKG_OPTIONS:Mlibdbi)
CMAKE_ARGS+=	-DWITH_SQL=ON
PLIST_SRC+=	PLIST.dbi
BUILD_DEPENDS+=	libdbi-driver-sqlite3-[0-9]*:../../databases/libdbi-driver-sqlite3
.include "../../databases/libdbi/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_SQL=OFF
.endif

.if !empty(PKG_OPTIONS:Mpython)
CMAKE_ARGS+=			-DWITH_PYTHON=ON
PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON+=		bindings/python/example_scripts/*.py
REPLACE_PYTHON+=		bindings/python/example_scripts/rest-api/*.py
REPLACE_PYTHON+=		gnucash/python/pycons/*.py
PY_PATCHPLIST=			yes
PLIST_SRC+=			PLIST.python

# /usr/pkg/share/gnucash/python/pycons/console.py imports readline
DEPENDS+=		${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.else
CMAKE_ARGS+=			-DWITH_PYTHON=OFF
.endif
