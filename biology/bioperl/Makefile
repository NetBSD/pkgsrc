# $NetBSD: Makefile,v 1.3 2001/02/16 13:41:26 wiz Exp $
#

DISTNAME=		bioperl-0.04.4
CATEGORIES=		biology
MASTER_SITES=		ftp://bio.perl.org/pub/DIST/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://bio.perl.org/
COMMENT=		Perl tools for computational molecular biology

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Bio/.packlist
PERL5_PACKLIST+=	${PERL5_SITEARCH}/auto/bp_sw/.packlist

do-configure:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL
	cd ${WRKSRC}/Compile/SW; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

pre-build:
	cd ${WRKSRC}/Compile/SW/libs; ${MAKE_PROGRAM}

post-build:
	cd ${WRKSRC}/Compile/SW; ${MAKE_PROGRAM}
	cd ${WRKSRC}; ${MAKE_PROGRAM} test
	cd ${WRKSRC}/Compile/SW; ${MAKE_PROGRAM} test

post-install:
	cd ${WRKSRC}/Compile/SW; ${MAKE_PROGRAM} install
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bioperl
	cd ${WRKSRC}/examples; ${GTAR} cf - . \
		| (cd ${PREFIX}/share/examples/bioperl; ${GTAR} xf -)

.include "../../mk/bsd.pkg.mk"
