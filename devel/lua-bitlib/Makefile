# $NetBSD: Makefile,v 1.1 2018/11/20 17:26:20 maya Exp $

DISTNAME=		bitlib-5.3.0
PKGNAME=		${LUA_PKGPREFIX}-${DISTNAME}
GITHUB_PROJECT=		lua-compat-5.2
GITHUB_TAG=		${DISTNAME}
MASTER_SITES=		${MASTER_SITE_GITHUB:=keplerproject/}

CATEGORIES=		devel
COMMENT=		Lua 5.2 bit manipulation library
MAINTAINER=		pkgsrc-users@NetBSD.org

HOMEPAGE=		https://github.com/keplerproject/lua-compat-5.2
LICENSE=		mit

LUA_VERSIONS_ACCEPTED=	51

NO_CONFIGURE=		yes

INSTALLATION_DIRS+=	${LUA_CDIR}/bit32

.include "../../lang/lua/module.mk"

do-build:
	${CC} ${CFLAGS} -fPIC -c -I ${WRKSRC}/c-api ${WRKSRC}/lbitlib.c -o ${WRKSRC}/bit32.o
	${LD} ${LDFLAGS} -fPIC -shared ${WRKSRC}/bit32.o -o ${WRKSRC}/bit32.so

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bit32.so \
	                ${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../mk/bsd.pkg.mk"
