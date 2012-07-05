# $NetBSD: Makefile,v 1.7 2012/07/05 16:07:18 drochner Exp $

PKGNAME=		libprelude-python-${VERSION}
PKGREVISION=		5
COMMENT=		Python bindings to LibPrelude

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../security/libprelude/Makefile.common"

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
