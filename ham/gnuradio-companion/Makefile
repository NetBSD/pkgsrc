# $NetBSD: Makefile,v 1.73 2023/10/28 08:43:05 mef Exp $

PKGNAME=	gnuradio-companion-${VERSION}
COMMENT=	User interface entry of GNU Radio

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

REPLACE_BASH=	grc/scripts/freedesktop/grc_setup_freedesktop.in

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

# gnuradio-companion
CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GRC=ON

ICON_THEMES=	yes
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
