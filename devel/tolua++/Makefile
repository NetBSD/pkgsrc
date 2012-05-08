# $NetBSD: Makefile,v 1.1.1.1 2012/05/08 09:34:17 imil Exp $
#

DISTNAME=	tolua++-1.0.93
CATEGORIES=	devel
MASTER_SITES=	http://www.codenix.com/~tolua/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://www.codenix.com/~tolua/
COMMENT=	Tool to integrate C/C++ code with Lua
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

BUILD_DEPENDS+=	scons-[0-9]*:../../devel/scons

INSTALLATION_DIRS+=	bin lib include share/doc/tolua++

SCONS=          ${PREFIX}/bin/scons
SCONS_ARGS=	prefix=${PREFIX} SONAME="libtolua++.so.${LUA_VERSION}"

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	custom.py
SUBST_SED.prefix=	-e 's|@PREFIX@|${PREFIX}|'

PLIST_SUBST+=		LUA_VERSION=${LUA_VERSION}

pre-patch:
	${CP} files/custom.py ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONS} ${SCONS_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tolua++ ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/lib/libtolua++.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib/libtolua++.so 			\
		${DESTDIR}${PREFIX}/lib/libtolua++.so.${LUA_VERSION}
	${LN} -sf ${DESTDIR}${PREFIX}/lib/libtolua++.so.${LUA_VERSION}	\
		${DESTDIR}${PREFIX}/lib/libtolua++.so
	${INSTALL_DATA} ${WRKSRC}/include/tolua++.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/README* ${DESTDIR}${PREFIX}/share/doc/tolua++
	${INSTALL_DATA} ${WRKSRC}/doc/tolua++.html			\
		${DESTDIR}${PREFIX}/share/doc/tolua++

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
