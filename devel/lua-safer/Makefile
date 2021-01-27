# $NetBSD: Makefile,v 1.1 2021/01/27 11:52:21 nia Exp $

DISTNAME=	safer-0.2
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=hishamhm/}
GITHUB_PROJECT=	safer
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hishamhm/safer
COMMENT=	Paranoid Lua programming
LICENSE=	mit

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}
INSTALLATION_DIRS+=	share/doc/${PKGBASE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/safer.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/safer.lua
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/LICENSE \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
