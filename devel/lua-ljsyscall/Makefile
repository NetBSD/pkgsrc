# $NetBSD: Makefile,v 1.1.1.1 2015/04/03 20:20:54 alnsn Exp $

DISTNAME=	ljsyscall-0.10
PKGNAME=	${DISTNAME:S/ljsyscall/${LUA_PKGPREFIX}-ljsyscall/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=justincormack/}
GITHUB_TAG=	v${PKGVERSION}
GITHUB_PROJECT=	${DISTNAME:S/-${PKGVERSION}//}

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	https://github.com/justincormack/ljsyscall
COMMENT=	LuaJIT syscall FFI for the Linux, NetBSD, FreeBSD and OSX kernels
LICENSE=	mit

.include "../../mk/bsd.prefs.mk"

NO_BUILD=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/syscall.lua \
	    ${DESTDIR}${PREFIX}/${LUA_LDIR}
	cd ${WRKSRC} && find syscall -name \*.lua \
	    | pax -rw ${DESTDIR}${PREFIX}/${LUA_LDIR}/

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
