# $NetBSD: Makefile,v 1.5 2014/05/03 13:01:24 alnsn Exp $

DISTNAME=		stdlib-28
PKGNAME=		${DISTNAME:S/stdlib/${LUA_PKGPREFIX}-stdlib/}
PKGREVISION=		2
CATEGORIES=		devel
COMMENT=		Standard library for Lua programming language
MASTER_SITES=		http://cloud.github.com/downloads/rrthomas/lua-stdlib/
EXTRACT_SUFX=		.zip
MAINTAINER=		cheusov@NetBSD.org

HOMEPAGE=		https://github.com/rrthomas/lua-stdlib
LICENSE=		mit

NO_BUILD=		yes
NO_CONFIGURE=		yes

INSTALLATION_DIRS+=	${LUA_LDIR} ${LUA_DOCDIR}/modules

.include "../../lang/lua/module.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}
	${INSTALL_DATA} ${WRKSRC}/src/*.html \
	                ${DESTDIR}${PREFIX}/${LUA_DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/src/modules/*.html \
	                ${DESTDIR}${PREFIX}/${LUA_DOCDIR}/modules/

.include "../../mk/bsd.pkg.mk"
