# $NetBSD: Makefile,v 1.9 2022/08/11 05:08:35 gutteridge Exp $

DISTNAME=	simutrans-src-121-0
PKGNAME=	${DISTNAME:S/-/./g:S/.src./-/1}
PKGREVISION=	6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=simutrans/}
CATEGORIES=	games
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://simutrans.com/
COMMENT=	Transportation simulation game
LICENSE=	gnu-gpl-v2

DEPENDS+=	simutrans-pak128-[0-9]*:../../games/simutrans-pak128

EXTRACT_DIR=	${WRKDIR}/simutrans
WRKSRC=		${WRKDIR}/simutrans

USE_TOOLS+=	gmake pax
USE_LANGUAGES=	c c++03

MAKE_FLAGS+=	BACKEND="mixer_sdl2"
MAKE_FLAGS+=	COLOUR_DEPTH="16"
MAKE_FLAGS+=	OSTYPE="linux"

MAKE_FLAGS+=	HOSTCC=${CC:Q}
MAKE_FLAGS+=	HOSTCXX=${CXX:Q}

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Setting path to PREFIX
SUBST_FILES.prefix+=	simmain.cc
SUBST_VARS.prefix+=	PREFIX

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/doc/simutrans
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps
INSTALLATION_DIRS+=	share/icons/hicolor/scalable/apps
INSTALLATION_DIRS+=	share/metainfo

CHECK_PORTABILITY_SKIP+=	OSX/binary_picker.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/default/sim \
	    ${DESTDIR}${PREFIX}/bin/simutrans
	${INSTALL_DATA} ${FILESDIR}/simutrans.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/simutrans.appdata.xml \
	    ${DESTDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${FILESDIR}/simutrans.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps
	${INSTALL_DATA} ${FILESDIR}/simutrans.svg \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	cd ${WRKSRC}/simutrans && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/simutrans
	${RM} -f ${DESTDIR}${PREFIX}/share/simutrans/*.txt
	${INSTALL_SCRIPT} ${FILESDIR}/get_pak.sh \
	    ${DESTDIR}${PREFIX}/share/simutrans/get_pak.sh
	${INSTALL_DATA} ${WRKSRC}/simutrans/*.txt \
	    ${DESTDIR}${PREFIX}/share/doc/simutrans

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
