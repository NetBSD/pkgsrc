# $NetBSD: Makefile,v 1.4 2017/07/04 22:35:03 alnsn Exp $

DISTNAME=	copas-2.0.2
PKGNAME=	${DISTNAME:S/copas/${LUA_PKGPREFIX}-copas/}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=keplerproject/}
GITHUB_TAG=	v${PKGVERSION:S/./_/g}
GITHUB_PROJECT=	${DISTNAME:S/-${PKGVERSION_NOREV}//}

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	http://keplerproject.github.io/copas
COMMENT=	Dispatcher based on coroutines that can be used by TCP_IP servers
LICENSE=	mit

DEPENDS+=	${LUA_PKGPREFIX}-coxpcall>=1.16.0:../../devel/lua-coxpcall
DEPENDS+=	${LUA_PKGPREFIX}-socket>=2.0:../../net/lua-socket
DEPENDS+=	${LUA_PKGPREFIX}-sec>=0.6:../../security/lua-sec

MAKE_ENV+=	LUA_LDIR=${LUA_LDIR:Q}
MAKE_ENV+=	LUA_INTERPRETER=${LUA_INTERPRETER:Q}

NO_BUILD=	yes
TEST_TARGET=	test

INSTALLATION_DIRS+=	${LUA_LDIR}/copas

INSTALL_COPAS_FILES=	${WRKSRC}/src/copas/ftp.lua
INSTALL_COPAS_FILES+=	${WRKSRC}/src/copas/smtp.lua
INSTALL_COPAS_FILES+=	${WRKSRC}/src/copas/http.lua
INSTALL_COPAS_FILES+=	${WRKSRC}/src/copas/limit.lua

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/copas.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}
	for f in ${INSTALL_COPAS_FILES}; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/${LUA_LDIR}/copas/ ; \
	done

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
