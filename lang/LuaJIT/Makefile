# $NetBSD: Makefile,v 1.5 2016/02/25 08:27:03 jperkin Exp $
#

DISTNAME=	LuaJIT-1.1.5
CATEGORIES=	lang
MASTER_SITES=	http://luajit.org/download/

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://luajit.org/
COMMENT=	Just-In-Time Compiler for the Lua programming language

# Only supports 32-bit x86. Try lang/LuaJIT2 instead...
ONLY_FOR_PLATFORM=	*-*-i386

LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_FLAGS+=	INSTALL_TOP=${PREFIX}

BUILD_TARGET.Linux=	linux
BUILD_TARGET.FreeBSD=	bsd
BUILD_TARGET.NetBSD=	bsd
BUILD_TARGET.OpenBSD=	bsd
BUILD_TARGET.Darwin=	macosx
BUILD_TARGET.SunOS=	solaris
BUILD_TARGET.*=		posix

.include "../../mk/bsd.pkg.mk"
