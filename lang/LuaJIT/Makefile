# $NetBSD: Makefile,v 1.3 2012/10/02 20:11:35 asau Exp $
#

DISTNAME=	LuaJIT-1.1.5
CATEGORIES=	lang
MASTER_SITES=	http://luajit.org/download/

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://luajit.org/
COMMENT=	Just-In-Time Compiler for the Lua programming language

ONLY_FOR_PLATFORM=	*-*-i386

LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_FLAGS+=	INSTALL_TOP=${PREFIX}

.include "../../mk/bsd.prefs.mk"

OPSYSVARS+=		BUILD_TARGET
BUILD_TARGET.Linux=	linux
BUILD_TARGET.FreeBSD=	bsd
BUILD_TARGET.NetBSD=	bsd
BUILD_TARGET.OpenBSD=	bsd
BUILD_TARGET.Darwin=	macosx
BUILD_TARGET.SunOS=	solaris
BUILD_TARGET.*=		posix

.include "../../mk/bsd.pkg.mk"
