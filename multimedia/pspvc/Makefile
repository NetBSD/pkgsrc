# $NetBSD: Makefile,v 1.20 2012/09/22 13:48:19 ryoon Exp $
#

DISTNAME=	pspvc-install-0.3
PSPVCVER=	pspvc-0.3
PKGNAME=	${PSPVCVER}
PKGREVISION=	16
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pspvc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pspvc.sf.net/
COMMENT=	PSP video converter

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	share/applications share/pspvc/bin

USE_LANGUAGES=	c
USE_TOOLS=	pkg-config gmake msgfmt
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PSPVCVER}

post-extract:
	${TAR} -C ${WRKDIR} -zxf ${WRKDIR}/${DISTNAME}/archives/${PSPVCVER}.tar.gz

post-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/archives/pspvc.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${LN} -s ${PREFIX}/bin/ffmpeg \
		${DESTDIR}${PREFIX}/share/pspvc/bin/ffmpeg

.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
