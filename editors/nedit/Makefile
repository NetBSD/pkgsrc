# $NetBSD: Makefile,v 1.20 2001/12/19 01:23:09 mjl Exp $

VERS=		5.2
DISTNAME=	nedit-${VERS}-src
PKGNAME=	nedit-${VERS}
CATEGORIES=	editors
MASTER_SITES=	http://ftp.nedit.org/ftp/v${VERS:S/./_/g}/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nedit.org/
COMMENT=	Motif based standard GUI style text editor

USE_BUILDLINK_ONLY=	YES
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

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/motif.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
