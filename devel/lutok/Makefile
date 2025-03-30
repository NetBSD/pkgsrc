# $NetBSD: Makefile,v 1.16 2025/03/30 07:51:22 wiz Exp $

DISTNAME=	lutok-0.6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=freebsd/}
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/freebsd/lutok/
COMMENT=	Lightweight C++ API for Lua
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++14
USE_LIBTOOL=		yes
USE_TOOLS=		pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/lutok
CONFIGURE_ARGS+=	--htmldir=${PREFIX}/share/doc/lutok/html
CONFIGURE_ARGS+=	--without-doxygen

MAKE_FLAGS+=		examplesdir=${PREFIX}/share/examples/lutok

PKGCONFIG_OVERRIDE=	lutok.pc.in

.include "options.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
