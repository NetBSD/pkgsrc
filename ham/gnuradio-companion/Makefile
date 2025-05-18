# $NetBSD: Makefile,v 1.96 2025/05/18 19:31:20 gdt Exp $

PKGNAME=	gnuradio-companion-${VERSION}
PKGREVISION=	3
COMMENT=	User interface entry of GNU Radio

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

REPLACE_BASH=	grc/scripts/freedesktop/grc_setup_freedesktop.in

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GRC=ON

ICON_THEMES=	yes

REPLACE_PYTHON+=	grc/blocks/variable_struct.block.yml.py
REPLACE_PYTHON+=	grc/main.py

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
