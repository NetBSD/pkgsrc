# $NetBSD: Makefile,v 1.9 2003/07/17 21:25:23 grant Exp $
#

DISTNAME=	spiceprm-0.11
WRKSRC=		${WRKDIR}/spiceprm
CATEGORIES=	cad
MASTER_SITES=	http://metalab.unc.edu/pub/Linux/apps/circuits/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Spice preprocessor for parameterized subcircuits

USE_BUILDLINK2=		YES
NO_BUILD=		YES
REPLACE_PERL=		spiceprm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/spiceprm ${PREFIX}/bin/spiceprm
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/spiceprm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/spiceprm
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/spiceprm
	${INSTALL_DATA} ${WRKSRC}/EXAMPLES ${PREFIX}/share/examples/spiceprm

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
