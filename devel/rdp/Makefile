# $NetBSD: Makefile,v 1.1 1998/07/31 16:32:22 agc Exp $

DISTNAME=	rdp1_5
PKGNAME=	rdp-1.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.dcs.rhbnc.ac.uk/pub/rdp/
EXTRACT_SUFX=	.tar

MAINTAINER=	packages@netbsd.org

EXTRACT_BEFORE_ARGS=	xf

WRKSRC=		${WRKDIR}/rdp
MAKEFILE=	makefile

NO_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rdp ${PREFIX}/bin
	-${MKDIR} ${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_case.ps ${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_supp.ps ${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_tut.ps ${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_user.ps ${PREFIX}/share/doc/rdp

.include "../../mk/bsd.pkg.mk"
