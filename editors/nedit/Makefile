# $NetBSD: Makefile,v 1.51 2012/10/03 11:43:38 asau Exp $

DISTNAME=	nedit-${VERS}-src
PKGNAME=	nedit-${VERS}
PKGREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_NEDIT:=v${VERS:S/./_/g}/} \
		${MASTER_SITE_SOURCEFORGE:=nedit/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nedit.org/
COMMENT=	Motif based standard GUI style text editor

VERS=		5.5
MASTER_SITE_NEDIT=	http://www.nedit.org/ftp/			\
			http://nl.nedit.org/ftp/			\
			ftp://nl.nedit.org/pub/NEdit/			\
			ftp://ftp.fu-berlin.de/unix/editors/nedit/	\
			http://gd.tuwien.ac.at/editors/nedit/NEdit/	\
			ftp://cri.univ-tlse1.fr/pub/unix/nedit/NEdit/	\
			ftp://ftp.chg.ru/pub/unix/editors/nedit/

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
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
