# $NetBSD: Makefile,v 1.25 2009/06/30 00:07:14 joerg Exp $

DISTNAME=		rdp1_5
PKGNAME=		rdp-1.5
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.cs.rhul.ac.uk/pub/rdp/	\
			ftp://ftp.cs.rhul.ac.uk/pub/rdp/old_versions/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cs.rhul.ac.uk/research/languages/projects/rdp.shtml
COMMENT=		Compiles attributed LL(1) grammars into recursive descent compilers

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

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
