# $NetBSD: Makefile,v 1.11 2004/04/12 00:54:40 snj Exp $
#

DISTNAME=	spiceprm-0.11
CATEGORIES=	cad
MASTER_SITES=	http://metalab.unc.edu/pub/Linux/apps/circuits/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Spice preprocessor for parameterized subcircuits

WRKSRC=			${WRKDIR}/spiceprm
USE_BUILDLINK3=		YES
NO_BUILD=		YES
REPLACE_PERL=		spiceprm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/spiceprm ${PREFIX}/bin/spiceprm
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/spiceprm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/spiceprm
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/spiceprm
	${INSTALL_DATA} ${WRKSRC}/EXAMPLES ${PREFIX}/share/examples/spiceprm

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
