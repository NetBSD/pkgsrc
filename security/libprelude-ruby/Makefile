# $NetBSD: Makefile,v 1.4 2011/04/22 13:44:35 obache Exp $

PKGNAME=		libprelude-ruby-${VERSION}
PKGREVISION=		2
COMMENT=                Ruby bindings to LibPrelude

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../security/libprelude/Makefile.common"

BUILD_DIRS=		bindings/ruby

PKG_OPTIONS_VAR=	PKG_OPTIONS.libprelude
PKG_SUPPORTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CFLAGS=			-O0 -ggdb
.endif

.include "../../devel/libltdl/convenience.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnutls/libgnutls-config.mk"
.include "../../security/libprelude/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
