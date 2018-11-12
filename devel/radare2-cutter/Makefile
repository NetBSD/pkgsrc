# $NetBSD: Makefile,v 1.8 2018/11/12 03:51:55 ryoon Exp $

DISTNAME=	cutter-1.2
PKGNAME=	radare2-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=radareorg/}
GITHUB_PROJECT=	cutter
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/radareorg/cutter/
COMMENT=	Qt and C++ GUI for radare2 reverse engineering framework
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

USE_CMAKE=	yes
USE_TOOLS+=	gmake pax pkg-config

WRKSRC=	${WRKDIR}/${DISTNAME}/src

CONFIGURE_DIRS=	${WRKDIR}/build
CMAKE_ARG_PATH=	${WRKSRC}

INSTALLATION_DIRS+=	bin share/applications share/icons/hicolor/scalable/apps
INSTALLATION_DIRS+=	share/doc/${PKGBASE}

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

do-install:
	${RUN} cd ${WRKDIR}/build && \
		${INSTALL_PROGRAM} cutter \
		${DESTDIR}${PREFIX}/bin/cutter
	${RUN} cd ${WRKSRC} && \
		${INSTALL_DATA} cutter.desktop \
		${DESTDIR}${PREFIX}/share/applications/cutter.desktop
	${RUN} cd ${WRKSRC} && \
		${INSTALL_DATA} img/cutter.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/cutter.svg
	${RUN} cd ${WRKDIR}/${DISTNAME}/docs && \
		${PAX} -wr * ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/radare2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
