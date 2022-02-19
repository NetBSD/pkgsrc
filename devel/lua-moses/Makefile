# $NetBSD: Makefile,v 1.2 2022/02/19 20:43:41 nia Exp $

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

TEST_DEPENDS+=	${LUA_PKGPREFIX}-cov-[0-9]*:../../devel/lua-cov

USE_LANGUAGES=	# none
NO_BUILD=	yes

LUA_USE_BUSTED=	yes

INSTALLATION_DIRS+=	${LUA_DOCDIR}
INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/${LUA_DOCDIR}/README.md
	${INSTALL_DATA} ${WRKSRC}/doc/tutorial.md \
		${DESTDIR}${PREFIX}/${LUA_DOCDIR}/tutorial.md
	${INSTALL_DATA} ${WRKSRC}/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
