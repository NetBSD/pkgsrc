# $NetBSD: Makefile,v 1.5 2001/06/27 11:41:51 zuntum Exp $
#

DISTNAME=	spiceprm-0.11
WRKSRC=		${WRKDIR}/spiceprm
CATEGORIES=	cad
MASTER_SITES=	http://metalab.unc.edu/pub/Linux/apps/circuits/

MAINTAINER=	packages@netbsd.org
COMMENT=	Spice preprocessor for parameterized subcircuits

NO_BUILD=	# defined
NO_CONFIGURE=	# defined
USE_PERL5=	# defined
REPLACE_PERL=	spiceprm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/spiceprm ${PREFIX}/bin/spiceprm
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/spiceprm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/spiceprm
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/spiceprm
	${INSTALL_DATA} ${WRKSRC}/EXAMPLES ${PREFIX}/share/examples/spiceprm

.include "../../mk/bsd.pkg.mk"
