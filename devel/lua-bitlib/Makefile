# $NetBSD: Makefile,v 1.3 2020/07/02 10:26:16 nia Exp $

DISTNAME=		bitlib-5.3.0
PKGNAME=		${LUA_PKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel lua
MASTER_SITES=		${MASTER_SITE_GITHUB:=keplerproject/}
GITHUB_PROJECT=		lua-compat-5.2
GITHUB_TAG=		${DISTNAME}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/keplerproject/lua-compat-5.2
COMMENT=		Lua 5.2 bit manipulation library
LICENSE=		mit

LUA_VERSIONS_ACCEPTED=	51

NO_CONFIGURE=		yes
USE_LIBTOOL=		yes

INSTALLATION_DIRS+=	${LUA_CDIR}

do-build:
	${LIBTOOL} --tag=CC --mode=compile ${CC} ${CFLAGS} -fPIC -I ${WRKSRC}/c-api -c -o ${WRKSRC}/bit32.lo ${WRKSRC}/lbitlib.c
	${LIBTOOL} --tag=CC --mode=link ${CC} ${LDFLAGS} -rpath ${PREFIX}/${LUA_CDIR} -shared -module -avoid-version -export-dynamic -o ${WRKSRC}/bit32.la ${WRKSRC}/bit32.lo

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/bit32.la ${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
