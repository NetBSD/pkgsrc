# $NetBSD: Makefile,v 1.20 2017/09/04 18:55:08 wiz Exp $
#

DISTNAME=	qiviewer-0.5.0
PKGREVISION=	16
CATEGORIES=	graphics
MASTER_SITES=	http://qiviewer.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/samkpo/qiviewer
COMMENT=	Qt image viewer, designed to be fast and lightweight
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/qiviewer/src
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

do-configure:
	(cd ${WRKSRC} && \
	${QTDIR}/bin/qmake \
		PREFIX=${DESTDIR}${PREFIX} \
		CONFIG+=enable-webp)

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
