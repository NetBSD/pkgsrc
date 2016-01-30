# $NetBSD: Makefile,v 1.1.1.1 2016/01/30 11:09:18 alnsn Exp $

DISTNAME=	LDoc-1.4.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=stevedonovan/}
GITHUB_TAG=	${PKGVERSION}
GITHUB_PROJECT=	${DISTNAME:S/-${PKGVERSION}//}

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	https://github.com/stevedonovan/LDoc
COMMENT=	Lua Documentation Tool
LICENSE=	mit

.include "../../mk/bsd.prefs.mk"

NO_BUILD=	yes
USE_TOOLS+=	pax

# LDoc works with any version but this package
# doesn't need to be multiversioned:
LUA_VERSIONS_ACCEPTED=	53

DEPENDS+=	${LUA_PKGPREFIX}-penlight-[0-9]*:../../devel/lua-penlight
DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem

REPLACE_LUA=	ldoc.lua

INSTALLATION_DIRS+=	bin ${LUA_LDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ldoc.lua \
	    ${DESTDIR}${PREFIX}/bin/ldoc
	cd ${WRKSRC} && find ldoc -type f \
	    | pax -rw ${DESTDIR}${PREFIX}/${LUA_LDIR}/

.include "../../lang/lua/module.mk"
.include "../../lang/lua/application.mk"
.include "../../mk/bsd.pkg.mk"
