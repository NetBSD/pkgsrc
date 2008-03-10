# $NetBSD: Makefile,v 1.9 2008/03/10 10:33:38 wiz Exp $

DISTNAME=		mtl-2.1.2-21
PKGNAME=		mtl-2.1.2.21
CATEGORIES=		math devel
MASTER_SITES=		http://www.osl.iu.edu/download/research/mtl/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.osl.iu.edu/research/mtl/
COMMENT=		Matrix Template Library

GNU_CONFIGURE=		yes
NO_BUILD=		yes

CONFLICTS+=		mtl-2.1.2-[0-9]*
USE_LANGUAGES=		c c++

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mtl
	${INSTALL_DATA} ${WRKSRC}/contrib/examples/*.cc	\
		${PREFIX}/share/examples/mtl
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mtl
	cd ${WRKSRC} && ${INSTALL_DATA} INSTALL LICENSE README	\
		${PREFIX}/share/doc/mtl

.include "../../mk/bsd.pkg.mk"
