# $NetBSD: Makefile,v 1.4 2001/02/16 13:46:28 wiz Exp $
#

DISTNAME=	spiceprm-0.11
WRKSRC=		${WRKDIR}/spiceprm
CATEGORIES=	cad
MASTER_SITES=	http://metalab.unc.edu/pub/Linux/apps/circuits/

MAINTAINER=	packages@netbsd.org
COMMENT=	Spice preprocessor for parameterized subcircuits

NO_CONFIGURE=	# defined
USE_PERL5=	# defined

do-build:
	${MV} ${WRKSRC}/spiceprm ${WRKSRC}/spiceprm.BAK
	${SED} 's!/usr/bin/perl!${PERL5}!g' \
	  < ${WRKSRC}/spiceprm.BAK > ${WRKSRC}/spiceprm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/spiceprm ${PREFIX}/bin/spiceprm
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/spiceprm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/spiceprm
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/spiceprm
	${INSTALL_DATA} ${WRKSRC}/EXAMPLES ${PREFIX}/share/examples/spiceprm

.include "../../mk/bsd.pkg.mk"
