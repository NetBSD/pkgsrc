# $NetBSD: Makefile,v 1.2 1998/08/01 22:30:26 frueauf Exp $

DISTNAME=		rdp1_5
PKGNAME=		rdp-1.5
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.dcs.rhbnc.ac.uk/pub/rdp/
EXTRACT_SUFX=		.zip

MAINTAINER=		packages@netbsd.org

BUILD_DEPENDS=		unzip:../../archivers/unzip

EXTRACT_CMD=		unzip
EXTRACT_BEFORE_ARGS=	-Laqo

WRKSRC=			${WRKDIR}/rdp
MAKEFILE=		makefile

NO_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rdp ${PREFIX}/bin
	-${MKDIR} ${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_case.ps ${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_supp.ps ${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_tut.ps ${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_user.ps ${PREFIX}/share/doc/rdp

.include "../../mk/bsd.pkg.mk"
