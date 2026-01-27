# $NetBSD: Makefile,v 1.28 2026/01/27 08:40:13 wiz Exp $

DISTNAME=	qt6gtk2-0.7
PKGREVISION=	1
CATEGORIES=	misc x11
MASTER_SITES=	https://www.opencode.net/trialuser/qt6gtk2/-/archive/${PKGVERSION_NOREV}/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://www.opencode.net/trialuser/qt6gtk2
COMMENT=	GTK+2.0 integration plugins for Qt6
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++11
USE_TOOLS=		pkg-config

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-O1

QMAKE_ARGS+=	qt6gtk2.pro
QMAKE_ARGS+=	QMAKE_CXXFLAGS=${CXXFLAGS:Q}
QMAKE_ARGS+=	PREFIX=${PREFIX}

DOCDIR=			share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${DOCDIR}
INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	${RUN}cd ${WRKSRC} &&			\
		${SETENV} ${CONFIGURE_ENV}	\
		${QTDIR}/bin/qmake ${QMAKE_ARGS}

post-install:
	${INSTALL_DATA}	${FILESDIR}/README	\
		${DESTDIR}${PREFIX}/${DOCDIR}/README

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
#.include "../../devel/cmake/build.mk"

.include "../../mk/bsd.pkg.mk"
