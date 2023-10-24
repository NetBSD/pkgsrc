# $NetBSD: Makefile,v 1.5 2023/10/24 22:08:53 wiz Exp $

DISTNAME=	luaevent-0.4.6
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua//1}
PKGREVISION=	1
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=harningt/}
GITHUB_PROJECT=	luaevent
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/harningt/luaevent
COMMENT=	Binding of libevent to Lua, with drop-in replacement for copas
LICENSE=	mit

BUILD_DIRS+=	src

INSTALLATION_DIRS+=	${LUA_DOCDIR}
INSTALLATION_DIRS+=	${LUA_DOCDIR}/modules
INSTALLATION_DIRS+=	${LUA_CDIR}/luaevent
INSTALLATION_DIRS+=	${LUA_LDIR}

pre-build:
	# There's an included Makefile, but doing it this way is better:
	# - The included Makefile does not benefit from make -j
	# - The included Makefile does not respect the environment
	# - The included Makefile requires gmake
	${CP} -f ${FILESDIR}/Makefile ${WRKSRC}/src/Makefile

do-install:
	${INSTALL_LIB} ${WRKSRC}/src/core.so \
		${DESTDIR}${PREFIX}/${LUA_CDIR}/luaevent/core.so
	${INSTALL_DATA} ${WRKSRC}/lua/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.mdwn \
		${DESTDIR}${PREFIX}/${LUA_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/modules/*.mdwn \
		${DESTDIR}${PREFIX}/${LUA_DOCDIR}/modules

do-test:
	# Set up the directory layout so Lua finds core.so without it
	# being installed system-wide.
	${MKDIR} -p ${WRKSRC}/test/luaevent
	${CP} -f ${WRKSRC}/src/core.so ${WRKSRC}/test/luaevent
	cd ${WRKSRC}/test && LUA_PATH=${WRKSRC}/lua/?.lua ${LUA_INTERPRETER} basic.lua

.include "../../lang/lua/module.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
