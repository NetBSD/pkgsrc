# $NetBSD: Makefile,v 1.33 2004/01/28 12:13:02 xtraeme Exp $

DISTNAME=	nedit-${VERS}-source
PKGNAME=	nedit-${VERS}
PKGREVISION=	1
CATEGORIES=	editors
#MASTER_SITES=	http://www.nedit.org/ftp/v${VERS:S/./_/g}/ \
#		http://www.au.nedit.org/ftp/v${VERS:S/./_/g}/ \
#		ftp://ftp.nl.nedit.org/pub/mirror/NEdit/v${VERS:S/./_/g}/
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nedit/}
#EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
#XXX nedit.org's ISP currently has problems
#HOMEPAGE=	http://www.nedit.org/
HOMEPAGE=	http://nedit.sourceforge.net/
COMMENT=	Motif based standard GUI style text editor

VERS=		5.4

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK2=		YES
USE_X11=		YES
ALL_TARGET=		netbsd

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
