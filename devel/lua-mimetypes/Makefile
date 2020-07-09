# $NetBSD: Makefile,v 1.1 2020/07/09 13:15:45 nia Exp $

DISTNAME=	lua-mimetypes-1.0.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/lua-//1}
CATEGORIES=	devel lua
MASTER_SITES=	-https://bitbucket.org/leafstorm/lua-mimetypes/get/v${PKGVERSION_NOREV}.tar.gz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://bitbucket.org/leafstorm/lua-mimetypes
COMMENT=	MIME type database for Lua
LICENSE=	mit

WRKSRC=		${WRKDIR}/leafstorm-lua-mimetypes-02100ff1171e
USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}
INSTALLATION_DIRS+=	share/doc/${PKGNAME_NOREV}

do-install:
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}
	${INSTALL_DATA} ${WRKSRC}/mimetypes.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/mimetypes.lua

do-test:
	cd ${WRKSRC} && ${LUA_INTERPRETER} test.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
