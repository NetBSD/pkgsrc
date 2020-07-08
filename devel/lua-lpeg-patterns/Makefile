# $NetBSD: Makefile,v 1.1 2020/07/08 13:48:33 nia Exp $

DISTNAME=	lpeg_patterns-0.5
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/_/-/g}
MASTER_SITES=	${MASTER_SITE_GITHUB:=daurnimator/}
CATEGORIES=	devel lua
GITHUB_PROJECT=	lpeg_patterns
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/daurnimator/lpeg_patterns
COMMENT=	Collection of LPEG patterns
LICENSE=	mit

DEPENDS+=	${LUA_PKGPREFIX}-lpeg-[0-9]*:../../devel/lua-lpeg

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}/lpeg_patterns

do-install:
	${INSTALL_DATA} ${WRKSRC}/lpeg_patterns/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/lpeg_patterns

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
