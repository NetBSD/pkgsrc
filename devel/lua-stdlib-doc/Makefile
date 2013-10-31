# $NetBSD: Makefile,v 1.4 2013/10/31 23:35:10 dholland Exp $

.include "../../devel/lua-stdlib/Makefile.common"

PKGNAME=		${DISTNAME:S/stdlib/lua-stdlib-doc/}
PKGREVISION=		1
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
