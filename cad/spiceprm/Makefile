# $NetBSD: Makefile,v 1.1.1.1 1999/09/30 15:13:25 dmcmahill Exp $
#

DISTNAME=	spiceprm-0.11
WRKSRC=		${WRKDIR}/spiceprm
CATEGORIES=	cad
MASTER_SITES=	http://metalab.unc.edu/pub/Linux/apps/circuits/

MAINTAINER=	packages@netbsd.org

NO_CONFIGURE=	YES
USE_PERL=	YES

do-build:
	${MV} ${WRKSRC}/spiceprm ${WRKSRC}/spiceprm.BAK
	${SED} 's!/usr/bin/perl!${LOCALBASE}/bin/perl!g' \
	  < ${WRKSRC}/spiceprm.BAK > ${WRKSRC}/spiceprm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/spiceprm ${PREFIX}/bin/spiceprm
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/spiceprm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/spiceprm
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/spiceprm
	${INSTALL_DATA} ${WRKSRC}/EXAMPLES ${PREFIX}/share/examples/spiceprm

.include "../../mk/bsd.pkg.mk"
