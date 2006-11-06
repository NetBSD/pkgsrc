# $NetBSD: Makefile,v 1.46 2006/11/06 11:08:37 joerg Exp $

DISTNAME=	nedit-${VERS}-src
PKGNAME=	nedit-${VERS}
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://www.nedit.org/ftp/v${VERS:S/./_/g}/ \
		${MASTER_SITE_SOURCEFORGE:=nedit/} \
		http://www.au.nedit.org/ftp/v${VERS:S/./_/g}/ \
		ftp://ftp.nl.nedit.org/pub/mirror/NEdit/v${VERS:S/./_/g}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nedit.org/
COMMENT=	Motif based standard GUI style text editor

PKG_DESTDIR_SUPPORT=	user-destdir

VERS=		5.5

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
BUILD_TARGET=		netbsd
INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/nedit ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/source/nc ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/nedit.man ${DESTDIR}${PREFIX}/man/man1/nedit.1
	${INSTALL_MAN} ${WRKSRC}/doc/nc.man ${DESTDIR}${PREFIX}/man/man1/nedit-nc.1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/nedit
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/nedit
	${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${DESTDIR}${PREFIX}/share/doc/nedit
	${INSTALL_DATA} ${WRKSRC}/doc/faq.txt ${DESTDIR}${PREFIX}/share/doc/nedit
	${INSTALL_DATA} ${WRKSRC}/doc/NEdit.ad ${DESTDIR}${PREFIX}/share/doc/nedit

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
