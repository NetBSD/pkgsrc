# $NetBSD: Makefile,v 1.6 2020/07/13 19:45:45 alnsn Exp $

DISTNAME=	ljsyscall-0.12
PKGNAME=	${DISTNAME:S/ljsyscall/${LUA_PKGPREFIX}-ljsyscall/}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=justincormack/}
GITHUB_TAG=	v${PKGVERSION}
GITHUB_PROJECT=	${DISTNAME:S/-${PKGVERSION}//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/justincormack/ljsyscall
COMMENT=	LuaJIT syscall FFI for the Linux, NetBSD, FreeBSD and OSX kernels
LICENSE=	mit

.include "../../mk/bsd.prefs.mk"

NO_BUILD=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	${LUA_LDIR}

DEPENDS+=	LuaJIT2>=2.0.2:../../lang/LuaJIT2

do-install:
	${INSTALL_DATA} ${WRKSRC}/syscall.lua \
	    ${DESTDIR}${PREFIX}/${LUA_LDIR}
	cd ${WRKSRC} && find syscall -name \*.lua \
	    | pax -rw ${DESTDIR}${PREFIX}/${LUA_LDIR}/

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
