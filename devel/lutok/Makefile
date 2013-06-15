# $NetBSD: Makefile,v 1.6 2013/06/15 00:30:31 jmmv Exp $
#

DISTNAME=	lutok-0.3
CATEGORIES=	devel
MASTER_SITES=	http://lutok.googlecode.com/files/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://code.google.com/p/kyua/
COMMENT=	Lightweight C++ API for Lua
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS=		pkg-config

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
