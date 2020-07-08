# $NetBSD: Makefile,v 1.1 2020/07/08 16:23:23 nia Exp $

DISTNAME=	busted-2.0.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=Olivine-Labs/}
GITHUB_PROJECT=	busted
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/Olivine-Labs/busted
COMMENT=	Elegant Lua unit testing
LICENSE=	mit

DEPENDS+=	${LUA_PKGPREFIX}-cliargs-[0-9]*:../../devel/lua-cliargs
DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem
DEPENDS+=	${LUA_PKGPREFIX}-system-[0-9]*:../../devel/lua-system
DEPENDS+=	${LUA_PKGPREFIX}-dkjson-[0-9]*:../../textproc/lua-dkjson
DEPENDS+=	${LUA_PKGPREFIX}-say-[0-9]*:../../devel/lua-say
DEPENDS+=	${LUA_PKGPREFIX}-luassert-[0-9]*:../../devel/lua-luassert
DEPENDS+=	${LUA_PKGPREFIX}-term-[0-9]*:../../devel/lua-term
DEPENDS+=	${LUA_PKGPREFIX}-penlight-[0-9]*:../../devel/lua-penlight
DEPENDS+=	${LUA_PKGPREFIX}-mediator-[0-9]*:../../devel/lua-mediator

NO_BUILD=	yes
USE_LANGUAGES=	# none

PLIST_SUBST+=	LUADOTVER=${_LUA_DOT_VERSION}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${LUA_LDIR}/busted
INSTALLATION_DIRS+=	${LUA_LDIR}/busted/modules
INSTALLATION_DIRS+=	${LUA_LDIR}/busted/modules/files
INSTALLATION_DIRS+=	${LUA_LDIR}/busted/outputHandlers
INSTALLATION_DIRS+=	${LUA_LDIR}/busted/languages

SUBST_CLASSES+=		lua
SUBST_MESSAGE.lua=	Fixing Lua interpreter path
SUBST_STAGE.lua=	pre-configure
SUBST_FILES.lua=	bin/busted
SUBST_SED.lua=		-e 's,/usr/bin/env lua,${LUA_INTERPRETER},g'

do-install:
	${INSTALL_DATA} ${WRKSRC}/busted/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/busted
	${INSTALL_DATA} ${WRKSRC}/busted/modules/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/busted/modules
	${INSTALL_DATA} ${WRKSRC}/busted/modules/files/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/busted/modules/files
	${INSTALL_DATA} ${WRKSRC}/busted/outputHandlers/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/busted/outputHandlers
	${INSTALL_DATA} ${WRKSRC}/busted/languages/*.lua \
	    	${DESTDIR}${PREFIX}/${LUA_LDIR}/busted/languages
	${INSTALL_PROGRAM} ${WRKSRC}/bin/busted \
		${DESTDIR}${PREFIX}/bin/busted${_LUA_DOT_VERSION}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
