# $NetBSD: Makefile,v 1.1 2020/07/11 11:56:59 nia Exp $

DISTNAME=	moonscript-0.5.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	lang lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=leafo/}
GITHUB_PROJECT=	moonscript
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://moonscript.org/
COMMENT=	Dynamic scripting language that compiles into Lua
LICENSE=	mit

DEPENDS+=	${LUA_PKGPREFIX}-alt-getopt>=0.7:../../devel/lua-alt-getopt
DEPENDS+=	${LUA_PKGPREFIX}-lpeg>=0.12:../../devel/lua-lpeg
DEPENDS+=	${LUA_PKGPREFIX}-filesystem>=1.5:../../devel/lua-filesystem

NO_BUILD=	yes
USE_LANGUAGES=	# none

PLIST_SUBST+=	LUADOTVER=${_LUA_DOT_VERSION}

REPLACE_LUA+=	bin/moon bin/moonc

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${LUA_DOCDIR}
INSTALLATION_DIRS+=	${LUA_LDIR}/moon

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/moon \
		${DESTDIR}${PREFIX}/bin/moon${_LUA_DOT_VERSION}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/moonc \
		${DESTDIR}${PREFIX}/bin/moonc${_LUA_DOT_VERSION}
	cd ${WRKSRC}/moonscript && ${FIND} * -type d -exec \
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${LUA_LDIR}/moonscript/'{}' ';'
	cd ${WRKSRC}/moonscript && ${FIND} * -name '*.lua' -exec \
		${INSTALL_DATA} '{}' ${DESTDIR}${PREFIX}/${LUA_LDIR}/moonscript/'{}' ';'
	${INSTALL_DATA} ${WRKSRC}/moon/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/moon
	${INSTALL_DATA} ${WRKSRC}/docs/*.md \
		${DESTDIR}${PREFIX}/${LUA_DOCDIR}

.include "../../lang/lua/application.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
