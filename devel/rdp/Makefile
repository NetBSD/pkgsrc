# $NetBSD: Makefile,v 1.13 2003/07/21 16:43:46 martti Exp $

DISTNAME=		rdp1_5
PKGNAME=		rdp-1.5
WRKSRC=			${WRKDIR}/rdp
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.dcs.rhbnc.ac.uk/pub/rdp/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.dcs.rhbnc.ac.uk/research/languages/rdp.shtml
COMMENT=		Compiles attributed LL(1) grammars into recursive descent compilers

MAKEFILE=		makefile

NO_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rdp ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_case.ps ${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_supp.ps ${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_tut.ps ${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_user.ps ${PREFIX}/share/doc/rdp

.include "../../mk/bsd.pkg.mk"
