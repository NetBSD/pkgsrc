# $NetBSD: Makefile,v 1.11 2012/09/11 23:04:24 asau Exp $

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

INSTALLATION_DIRS+=	share/doc/mtl share/examples/mtl

INSTALL_MAKE_FLAGS+=	includedir=${DESTDIR}${PREFIX}/include/mtl

post-install:
	${INSTALL_DATA} ${WRKSRC}/contrib/examples/*.cc	\
	    ${DESTDIR}${PREFIX}/share/examples/mtl
	cd ${WRKSRC} && ${INSTALL_DATA} INSTALL LICENSE README	\
	    ${DESTDIR}${PREFIX}/share/doc/mtl

.include "../../mk/bsd.pkg.mk"
