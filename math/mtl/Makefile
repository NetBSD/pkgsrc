# $NetBSD: Makefile,v 1.12 2012/09/13 18:13:50 asau Exp $

DISTNAME=		mtl-2.1.2-22
PKGNAME=		mtl-2.1.2.22
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
	cd ${WRKSRC} && ${INSTALL_DATA} INSTALL license.mtl.txt README	\
	    ${DESTDIR}${PREFIX}/share/doc/mtl

do-test:
	cd $(WRKSRC)/test && $(PERL5) ./bin/make_and_test.pl $(QUICK) -d ./src 

.include "../../mk/bsd.pkg.mk"
