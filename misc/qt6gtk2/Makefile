# $NetBSD: Makefile,v 1.9 2024/05/29 16:33:39 adam Exp $

DISTNAME=	qt6gtk2-0.2
PKGREVISION=	8
CATEGORIES=	misc x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=trialuser02/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/trialuser02/qt6ct/
COMMENT=	GTK+2.0 integration plugins for Qt6
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++11
USE_TOOLS=		pkg-config

GCC_REQD+=	9 #qt6

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
