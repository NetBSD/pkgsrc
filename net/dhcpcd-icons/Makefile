# $NetBSD: Makefile,v 1.2 2023/04/24 00:07:47 roy Exp $
#

PKGNAME=		dhcpcd-icons-${DHCPCD_UI_VERSION}
CATEGORIES=		net
COMMENT=		Shared icons for dhcpcd-gtk and dhcpcd-qt

.include "Makefile.common"

CONFIGURE_ARGS+=	--with-icons

# dhcpcd-gtk-0.6.0 installed its own icons
CONFLICTS=		dhcpcd-gtk<0.7

TOOL_DEPENDS+=		py*-cairosvg-[0-9]*:../../converters/py-cairosvg

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
