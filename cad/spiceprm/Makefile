# $NetBSD: Makefile,v 1.18 2012/10/03 21:54:00 wiz Exp $
#

DISTNAME=	spiceprm-0.11
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/apps/circuits/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spice preprocessor for parameterized subcircuits

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/spiceprm
NO_BUILD=		YES
USE_TOOLS+=		perl:run
REPLACE_PERL=		spiceprm
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/spiceprm ${DESTDIR}${PREFIX}/bin/spiceprm
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/spiceprm
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/spiceprm
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/spiceprm
	${INSTALL_DATA} ${WRKSRC}/EXAMPLES ${DESTDIR}${PREFIX}/share/examples/spiceprm

.include "../../mk/bsd.pkg.mk"
