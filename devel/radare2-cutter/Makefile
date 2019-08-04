# $NetBSD: Makefile,v 1.14 2019/08/04 14:32:58 ryoon Exp $

DISTNAME=	cutter-1.8.3
PKGNAME=	radare2-${DISTNAME}
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

INSTALLATION_DIRS+=	bin share/icons/hicolor/scalable/apps
INSTALLATION_DIRS+=	share/doc/${PKGBASE}

NOT_PAX_MPROTECT_SAFE+=	bin/Cutter

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

do-install:
	${RUN} cd ${WRKDIR}/build && \
		${INSTALL_PROGRAM} Cutter \
		${DESTDIR}${PREFIX}/bin/Cutter
	${RUN} cd ${WRKSRC} && \
		${INSTALL_DATA} img/cutter.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/cutter.svg
	${RUN} cd ${WRKDIR}/${DISTNAME}/docs && \
		${PAX} -wr * ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/radare2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
