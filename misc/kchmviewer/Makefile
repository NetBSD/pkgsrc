# $NetBSD: Makefile,v 1.121 2024/05/29 16:33:32 adam Exp $

DISTNAME=		kchmviewer-7.2.1
PKGREVISION=		73
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kchmviewer/}

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://www.kchmviewer.net/
COMMENT=		CHM (MS HTML help file format) viewer
LICENSE=		gnu-gpl-v3

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES

WRKSRC=			${WRKDIR}/kchmviewer-7.2

LDFLAGS.SunOS+=		-lsocket -lnsl

SUBST_CLASSES+=		zip
SUBST_SED.zip+=		-e 's,-I${PREFIX}/include,-I${PREFIX}/include -I${PREFIX}/lib/libzip/include,'
SUBST_MESSAGE.zip=	Add missing header search path.
SUBST_FILES.zip+=	lib/libebook/Makefile
SUBST_STAGE.zip=	post-configure

CHECK_PORTABILITY_SKIP=	build-win32-mingw.sh

INSTALLATION_DIRS=	bin

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QTDIR}/bin/qmake
	cd ${WRKSRC}/lib && ${SETENV} ${MAKE_ENV} ${QTDIR}/bin/qmake
	cd ${WRKSRC}/lib/libebook && ${SETENV} ${MAKE_ENV} ${QTDIR}/bin/qmake

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKEFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/kchmviewer ${DESTDIR}${PREFIX}/bin

.include "../../archivers/libzip/buildlink3.mk"
.include "../../devel/chmlib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
