# $NetBSD: Makefile,v 1.16 2023/10/24 22:09:34 wiz Exp $

DISTNAME=	fcitx5-configtool-5.0.3
PKGREVISION=	9
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-configtool/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-configtool
COMMENT=	Config tool for fcitx5
LICENSE=	gnu-gpl-v2

BROKEN+=	"Incompatible with latest extra-cmake-modules, see https://bytemeta.vip/repo/fcitx/fcitx5-configtool/issues/38"

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

TOOL_DEPENDS+=		extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

OBJDIR=			${WRKDIR}/build
CONFIGURE_DIRS=		${OBJDIR}
CMAKE_ARG_PATH=		${WRKSRC}

CMAKE_ARGS+=		-DENABLE_KCM=off

pre-configure:
	${MKDIR} ${WRKDIR}/build

#.include "../../devel/kcoreaddons/buildlink3.mk"
#.include "../../devel/kdeclarative/buildlink3.mk"
#.include "../../devel/ki18n/buildlink3.mk"
#.include "../../devel/kpackage/buildlink3.mk"
.include "../../inputmethod/fcitx5-qt/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
#.include "../../x11/kirigami2/buildlink3.mk"
.include "../../x11/kitemviews/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
#.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
