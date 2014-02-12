# $NetBSD: Makefile,v 1.16 2014/02/12 23:18:03 tron Exp $
#

DISTNAME=	qiviewer-0.5.0
PKGREVISION=	14
CATEGORIES=	graphics
MASTER_SITES=	http://qiviewer.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/qiviewer/
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

SUBST_CLASSES+=			fix-target
SUBST_STAGE.fix-target=		post-configure
SUBST_MESSAGE.fix-target=	Replace QMAKE_TARGET with TARGET
SUBST_FILES.fix-target+=	Makefile
SUBST_SED.fix-target+=		-e 's/(QMAKE_TARGET)/{TARGET}/'

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
