# $NetBSD: Makefile,v 1.13 2016/09/08 15:19:18 joerg Exp $

PKGNAME=		libprelude-ruby-${VERSION}
PKGREVISION=		8
COMMENT=                Ruby bindings to LibPrelude

.include "../../security/libprelude/Makefile.common"

RUBY_VERSIONS_ACCEPTED=	18
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
