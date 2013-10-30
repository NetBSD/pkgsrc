# $NetBSD: Makefile,v 1.8 2013/10/30 06:49:53 dholland Exp $

DISTNAME=	lutok-0.3
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://lutok.googlecode.com/files/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://code.google.com/p/lutok/
COMMENT=	Lightweight C++ API for Lua
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS=		pkg-config
GNU_CONFIGURE=		yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.lutok
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS=	tests

CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/lutok
CONFIGURE_ARGS+=	--htmldir=${PREFIX}/share/doc/lutok/html
CONFIGURE_ARGS+=	--without-doxygen

MAKE_FLAGS+=		examplesdir=${PREFIX}/share/examples/lutok

PKGCONFIG_OVERRIDE=	lutok.pc.in

.include "../../mk/bsd.options.mk"

.if $(PKG_OPTIONS:Mtests)
CONFIGURE_ARGS+=	--with-atf
PLIST_SUBST+=		TESTS=
.  include "../../devel/atf-libs/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-atf
PLIST_SUBST+=		TESTS=@comment
.endif

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
