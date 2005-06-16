# $NetBSD: Makefile,v 1.42 2005/06/16 06:57:49 jlam Exp $

DISTNAME=	nedit-${VERS}-src
PKGNAME=	nedit-${VERS}
CATEGORIES=	editors
MASTER_SITES=	http://www.nedit.org/ftp/v${VERS:S/./_/g}/ \
		${MASTER_SITE_SOURCEFORGE:=nedit/} \
		http://www.au.nedit.org/ftp/v${VERS:S/./_/g}/ \
		ftp://ftp.nl.nedit.org/pub/mirror/NEdit/v${VERS:S/./_/g}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nedit.org/
COMMENT=	Motif based standard GUI style text editor

VERS=		5.5

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
BUILD_TARGET=		netbsd
INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/nedit ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/source/nc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/nedit.man ${PREFIX}/man/man1/nedit.1
	${INSTALL_MAN} ${WRKSRC}/doc/nc.man ${PREFIX}/man/man1/nedit-nc.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nedit
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nedit
	${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${PREFIX}/share/doc/nedit
	${INSTALL_DATA} ${WRKSRC}/doc/faq.txt ${PREFIX}/share/doc/nedit
	${INSTALL_DATA} ${WRKSRC}/doc/NEdit.ad ${PREFIX}/share/doc/nedit

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
