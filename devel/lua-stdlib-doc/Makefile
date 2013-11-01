# $NetBSD: Makefile,v 1.5 2013/11/01 18:17:43 jperkin Exp $

.include "../../devel/lua-stdlib/Makefile.common"

PKGNAME=		${DISTNAME:S/stdlib/${LUA_PKGPREFIX}-stdlib-doc/}
PKGREVISION=		2
MAINTAINER=		cheusov@NetBSD.org

COMMENT=		Documentation for modules from lua-stdlib

DOCDIR=			share/doc/lua-stdlib

DEPENDS+=		${LUA_PKGPREFIX}-${DISTNAME}{,nb*}:../../devel/lua-stdlib
INSTALLATION_DIRS+=	${DOCDIR}/modules

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/*.html \
	                ${DESTDIR}${PREFIX}/${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/src/modules/*.html \
	                ${DESTDIR}${PREFIX}/${DOCDIR}/modules/

.include "../../lang/lua/luaversion.mk" # for LUA_PKGPREFIX
.include "../../mk/bsd.pkg.mk"
