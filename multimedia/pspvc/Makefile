# $NetBSD: Makefile,v 1.31 2014/05/05 00:48:12 ryoon Exp $
#

DISTNAME=	pspvc-install-0.3
PSPVCVER=	pspvc-0.3
PKGNAME=	${PSPVCVER}
PKGREVISION=	26
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pspvc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pspvc.sf.net/
COMMENT=	PSP video converter

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
