# $NetBSD: Makefile,v 1.11 2014/05/03 13:14:37 alnsn Exp $

DISTNAME=	lutok-0.4
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
.  include "../../devel/atf/buildlink3.mk"
CONFIGURE_ARGS+=	--with-atf
PLIST_SUBST+=		TESTS=
.else
CONFIGURE_ARGS+=	--without-atf
PLIST_SUBST+=		TESTS=@comment
.endif

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
