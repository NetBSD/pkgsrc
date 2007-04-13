# $NetBSD: Makefile,v 1.48 2007/04/13 06:47:18 xtraeme Exp $

DISTNAME=	nedit-${VERS}-src
PKGNAME=	nedit-${VERS}
PKGREVISION=	3
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
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/nedit ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/source/nc ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/nedit.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nedit.1
	${INSTALL_MAN} ${WRKSRC}/doc/nc.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nedit-nc.1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/nedit
.for f in README ReleaseNotes
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/nedit
.endfor
.for f in faq.txt NEdit.ad
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DESTDIR}${PREFIX}/share/doc/nedit
.endfor

.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
