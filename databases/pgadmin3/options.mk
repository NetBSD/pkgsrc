# $NetBSD: options.mk,v 1.3 2018/05/10 07:12:53 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pgadmin3
PKG_SUPPORTED_OPTIONS=	doc

.include "../../mk/bsd.options.mk"

PLIST_VARS=	doc

.if !empty(PKG_OPTIONS:Mdoc)
PLIST.doc=	yes
PYTHON_FOR_BUILD_ONLY=yes
.include "../../lang/python/pyversion.mk"
BUILD_DEPENDS+=		${PYPKGPREFIX}-sphinx>=1.0:../../textproc/py-sphinx
CONFIGURE_ARGS+=	--with-sphinx-build=${PREFIX}/bin/sphinx-build${PYVERSSUFFIX}
.else
CONFIGURE_ENV+=		ac_cv_path_SPHINX_BUILD=
.endif
