# $NetBSD: Makefile,v 1.5 2009/06/12 17:24:54 ahoka Exp $
#

DISTNAME=	pspvc-install-0.3
PSPVCVER=	pspvc-0.3
PKGNAME=	${PSPVCVER}
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pspvc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pspvc.sf.net/
COMMENT=	PSP video converter

USE_LANGUAGES=	c
USE_TOOLS=	pkg-config gmake msgfmt
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PSPVCVER}

post-extract:
	${TAR} -C ${WRKDIR} -zxf ${WRKDIR}/${DISTNAME}/archives/${PSPVCVER}.tar.gz

post-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/archives/pspvc.desktop ${PREFIX}/share/applications
	${INSTALL_DATA_DIR} ${PREFIX}/share/pspvc/bin
	${LN} -s ${PREFIX}/bin/ffmpeg ${PREFIX}/share/pspvc/bin/ffmpeg

.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
