# $NetBSD: Makefile,v 1.2 2013/01/04 21:42:42 wiz Exp $
#

VER=		0.3.7
DISTNAME=	qpdfview-${VER}
CATEGORIES=	print
MASTER_SITES=	https://launchpad.net/qpdfview/trunk/${VER}/+download/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://launchpad.net/qpdfview
COMMENT=	Tabbed PDF viewer
LICENSE=	gnu-gpl-v2

# Force using "curl" for fetching the distribution file. It is only available
# over HTTPS and "curl" is the only fetch program which always supports HTTPS.
FETCH_USING=	curl

DEPENDS+=	poppler-data-[0-9]*:../../print/poppler-data

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fix install path
SUBST_FILES.prefix+=	qpdfview.pri
SUBST_VARS.prefix+=	DESTDIR PREFIX PKGMANDIR

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

do-configure:
	cd ${WRKSRC} && QTDIR=${QTDIR} \
		${QTDIR}/bin/qmake qpdfview.pro

.include "../../print/cups/buildlink3.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
