# $NetBSD: Makefile,v 1.12 2024/05/16 06:14:46 wiz Exp $

DISTNAME=	iaito-5.8.0
PKGREVISION=	11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=radareorg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/radareorg/iaito/
COMMENT=	Official Qt frontend of radare2
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ENV+=	LRELEASE=${QTDIR}/bin/lrelease
CONFIGURE_ENV+=	QMAKE=${QTDIR}/bin/qmake

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Setting the prefix
SUBST_STAGE.prefix=	post-configure
SUBST_FILES.prefix=	src/Iaito.pro
SUBST_SED.prefix=	-e 's;-Wl,-rpath,/usr/local/lib;${COMPILER_RPATH_FLAG}${PREFIX}/lib ${COMPILER_RPATH_FLAG}${QTDIR}/lib;g'
SUBST_SED.prefix+=	-e 's;/usr/local;${PREFIX};g'
SUBST_VARS.prefix=	PREFIX

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/radare2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
