# $NetBSD: options.mk,v 1.4 2019/10/21 21:19:35 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pgadmin3
PKG_SUPPORTED_OPTIONS=	doc

.include "../../mk/bsd.options.mk"

PLIST_VARS=	doc

.if !empty(PKG_OPTIONS:Mdoc)
PLIST.doc=	yes
PYTHON_FOR_BUILD_ONLY=yes
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/versioned_dependencies.mk"
PYTHON_VERSIONED_DEPENDENCIES=	sphinx:build
CONFIGURE_ARGS+=	--with-sphinx-build=${PREFIX}/bin/sphinx-build-${PYVERSSUFFIX}
.else
CONFIGURE_ENV+=		ac_cv_path_SPHINX_BUILD=
.endif
