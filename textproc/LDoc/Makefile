# $NetBSD: Makefile,v 1.2 2016/06/06 23:19:07 alnsn Exp $

DISTNAME=	LDoc-1.4.3
PKGNAME=	${DISTNAME:S/LDoc/${LUA_PKGPREFIX}-LDoc/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=stevedonovan/}
GITHUB_TAG=	${PKGVERSION}
GITHUB_PROJECT=	${DISTNAME:S/-${PKGVERSION_NOREV}//}

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	https://github.com/stevedonovan/LDoc
COMMENT=	Lua Documentation Tool
LICENSE=	mit

.include "../../mk/bsd.prefs.mk"

NO_BUILD=	yes
USE_TOOLS+=	pax

DEPENDS+=	${LUA_PKGPREFIX}-penlight-[0-9]*:../../devel/lua-penlight
DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem

REPLACE_LUA=	ldoc.lua

# XXX Add subst rules to ../../lang/lua/xxx.mk
PLIST_SUBST+=		LUADOTVER=${_LUA_DOT_VERSION}
FILES_SUBST+=		LUADOTVER=${_LUA_DOT_VERSION}

INSTALLATION_DIRS+=	bin ${LUA_LDIR}

WRKSRC=${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ldoc.lua \
	    ${DESTDIR}${PREFIX}/bin/ldoc${_LUA_DOT_VERSION}
	cd ${WRKSRC} && find ldoc -type f \
	    | pax -rw ${DESTDIR}${PREFIX}/${LUA_LDIR}/

.include "../../lang/lua/module.mk"
.include "../../lang/lua/application.mk"
.include "../../mk/bsd.pkg.mk"
