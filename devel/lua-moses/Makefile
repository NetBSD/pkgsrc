# $NetBSD: Makefile,v 1.1 2020/07/10 12:08:28 nia Exp $

DISTNAME=	Moses-2.1.0-1
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:tl:S/-1$//1}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=Yonaba/}
GITHUB_PROJECT=	Moses
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yonaba.github.io/Moses/
COMMENT=	Utility library for functional programming in Lua
LICENSE=	mit

TEST_DEPENDS+=	${LUA_PKGPREFIX}-busted-[0-9]*:../../devel/lua-busted
TEST_DEPENDS+=	${LUA_PKGPREFIX}-cov-[0-9]*:../../devel/lua-cov

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_DOCDIR}
INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/${LUA_DOCDIR}/README.md
	${INSTALL_DATA} ${WRKSRC}/doc/tutorial.md \
		${DESTDIR}${PREFIX}/${LUA_DOCDIR}/tutorial.md
	${INSTALL_DATA} ${WRKSRC}/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/busted${_LUA_DOT_VERSION}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
