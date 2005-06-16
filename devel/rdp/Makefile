# $NetBSD: Makefile,v 1.18 2005/06/16 06:57:47 jlam Exp $

DISTNAME=		rdp1_5
PKGNAME=		rdp-1.5
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.dcs.rhbnc.ac.uk/pub/rdp/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.dcs.rhbnc.ac.uk/research/languages/rdp.shtml
COMMENT=		Compiles attributed LL(1) grammars into recursive descent compilers

WRKSRC=			${WRKDIR}/rdp
MAKEFILE=		makefile

NO_CONFIGURE=		yes
USE_LANGUAGES=		c c++

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rdp ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_case.ps ${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_supp.ps ${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_tut.ps ${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_user.ps ${PREFIX}/share/doc/rdp

.include "../../mk/bsd.pkg.mk"
