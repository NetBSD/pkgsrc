# $NetBSD: Makefile,v 1.1.1.1 1999/04/16 14:43:35 rh Exp $
#

DISTNAME=	bioperl-0.04.4
CATEGORIES=	biology
MASTER_SITES=	ftp://bio.perl.org/pub/DIST/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://bio.perl.org/

USE_PERL5=	yes

do-configure:
	cd ${WRKSRC}; perl Makefile.PL
	cd ${WRKSRC}/Compile/SW; perl Makefile.PL

pre-build:
	cd ${WRKSRC}/Compile/SW/libs; make

post-build:
	cd ${WRKSRC}/Compile/SW; make
	cd ${WRKSRC}; make test
	cd ${WRKSRC}/Compile/SW; make test

post-install:
	cd ${WRKSRC}/Compile/SW; make install
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bioperl
	cd ${WRKSRC}/examples; ${GTAR} cf - . \
		| (cd ${PREFIX}/share/examples/bioperl; ${GTAR} xf -)

.include "../../mk/bsd.pkg.mk"
