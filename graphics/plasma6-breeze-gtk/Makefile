# $NetBSD: Makefile,v 1.1 2025/12/23 10:35:14 markd Exp $

DISTNAME=	breeze-gtk-${PLASMAVER}
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	Breeze widget theme for GTK 2 and 3
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/plasma6.mk"

TOOL_DEPENDS+=	sassc-[0-9]*:../../www/sassc
TOOL_DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo

pre-configure:
	ln -s ${PREFIX}/share/color-schemes ${BUILDLINK_DIR}/share/color-schemes

.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../graphics/plasma6-breeze/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
