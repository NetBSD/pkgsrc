# $NetBSD: Makefile,v 1.32 2023/12/29 00:45:38 zafer Exp $

DISTNAME=		rdp1_5
PKGNAME=		rdp-1.5
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		#
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.cs.rhul.ac.uk/research/languages/projects/rdp.html
COMMENT=		Compiles attributed LL(1) grammars into recursive descent compilers

MAKE_JOBS_SAFE=		no

EXTRACT_OPTS_ZIP=	-Laqo
WRKSRC=			${WRKDIR}/rdp
MAKE_FILE=		makefile

NO_CONFIGURE=		yes
USE_LANGUAGES=		c c++

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rdp ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_case.ps ${DESTDIR}${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_supp.ps ${DESTDIR}${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_tut.ps ${DESTDIR}${PREFIX}/share/doc/rdp
	${INSTALL_DATA} ${WRKSRC}/rdp_doc/rdp_user.ps ${DESTDIR}${PREFIX}/share/doc/rdp

.include "../../mk/bsd.pkg.mk"
