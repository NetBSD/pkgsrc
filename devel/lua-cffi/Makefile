# $NetBSD: Makefile,v 1.3 2026/11/16 12:01:42 wiz Exp $

DISTNAME=	cffi-lua-0.2.4
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/cffi-lua/cffi/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=q66/}
GITHUB_PROJECT=	cffi-lua
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/q66/cffi-lua/
COMMENT=	Portable C FFI for Lua
LICENSE=	mit

USE_LANGUAGES=		c++
USE_CXX_FEATURES=	c++14
USE_TOOLS+=		pkg-config
WRKSRC=			${WRKDIR}/${DISTNAME}

PLIST_SUBST+=		LUA_VERSION=${_LUA_DOT_VERSION}

.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
