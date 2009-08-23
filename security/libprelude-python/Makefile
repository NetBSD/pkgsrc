# $NetBSD: Makefile,v 1.1.1.1 2009/08/23 19:05:56 hasso Exp $

.include "../../security/libprelude/Makefile.common"
.include "../../mk/bsd.prefs.mk"

PATCHDIR=		${.CURDIR}/../libprelude/patches
PKGNAME=		libprelude-python-${VERSION}

COMMENT=		Python bindings to LibPrelude

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
PY_PATCHPLIST=		yes

BUILD_DIRS=		bindings/low-level/python bindings/python

PKG_OPTIONS_VAR=	PKG_OPTIONS.libprelude
PKG_SUPPORTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CFLAGS=			-O0 -ggdb
.endif

.include "../../devel/libltdl/convenience.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnutls/libgnutls-config.mk"
.include "../../security/libprelude/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
