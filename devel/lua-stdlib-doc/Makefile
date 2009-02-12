# $NetBSD: Makefile,v 1.1.1.1 2009/02/12 01:47:49 minskim Exp $

.include "../../devel/lua-stdlib/Makefile.common"

PKGNAME=		${DISTNAME:S/stdlib/lua-stdlib-doc/}

COMMENT=		Documentation for modules from lua-stdlib

DEPENDS+=		lua-stdlib-[0-9]*:../../devel/lua-stdlib

DOCDIR=			share/doc/lua-stdlib

INSTALLATION_DIRS+=	${DOCDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/modules/*.html \
	                ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/bsd.pkg.mk"
