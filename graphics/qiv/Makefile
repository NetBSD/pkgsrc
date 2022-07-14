# $NetBSD: Makefile,v 1.67 2022/07/14 23:46:24 dholland Exp $

DISTNAME=	qiv-2.3.2
PKGREVISION=	3
CATEGORIES=	graphics x11
MASTER_SITES=	https://spiegl.de/qiv/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://spiegl.de/qiv/
COMMENT=	Quick Image Viewer
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/qiv share/pixmaps
INSTALLATION_DIRS+=	share/applications

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qiv ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/qiv.1 ${DESTDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/qiv.png ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/qiv.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/qiv-command.example \
		${DESTDIR}${PREFIX}/share/examples/qiv

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
