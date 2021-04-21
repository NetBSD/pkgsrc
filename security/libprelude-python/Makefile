# $NetBSD: Makefile,v 1.30 2021/04/21 13:25:19 adam Exp $

PKGNAME=		libprelude-python-${VERSION}
PKGREVISION=		17
COMMENT=		Python bindings to LibPrelude

.include "../../security/libprelude/Makefile.common"

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
PY_PATCHPLIST=		yes

BUILD_DIRS=		bindings/low-level/python bindings/python

PKG_OPTIONS_VAR=	PKG_OPTIONS.libprelude
PKG_SUPPORTED_OPTIONS=	debug

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.9.24.1

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
