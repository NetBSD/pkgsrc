# $NetBSD: Makefile,v 1.25 2002/09/21 11:19:07 jlam Exp $

VERS=		5.3
DISTNAME=	nedit-${VERS}-source
PKGNAME=	nedit-${VERS}
CATEGORIES=	editors
MASTER_SITES=	http://www.nedit.org/ftp/v${VERS:S/./_/g}/ \
		http://www.au.nedit.org/ftp/v${VERS:S/./_/g}/ \
		ftp://ftp.nl.nedit.org/pub/mirror/NEdit/v${VERS:S/./_/g}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nedit.org/
COMMENT=	Motif based standard GUI style text editor

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
ALL_TARGET=		netbsd

WRKSRC=	${WRKDIR}/${PKGNAME}

do-install:
.for PROGRAM in nc nedit
	${INSTALL_PROGRAM} ${WRKSRC}/source/${PROGRAM} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PROGRAM}.man ${PREFIX}/man/man1/${PROGRAM}.1
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nedit
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nedit
	${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${PREFIX}/share/doc/nedit
	${INSTALL_DATA} ${WRKSRC}/doc/faq.txt ${PREFIX}/share/doc/nedit
	${INSTALL_DATA} ${WRKSRC}/doc/NEdit.ad ${PREFIX}/share/doc/nedit

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
