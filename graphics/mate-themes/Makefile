# $NetBSD: Makefile,v 1.1 2016/05/21 18:56:08 youri Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-themes-3.20.5
CATEGORIES=	graphics
MASTER_SITES=	http://pub.mate-desktop.org/releases/themes/3.20/

COMMENT=	Icons and themes for MATE desktop

DEPENDS+=	gtk2-engines-[0-9]*:../../x11/gtk2-engines
DEPENDS+=	gtk2-engines-murrine>=0.98.0:../../x11/gtk2-engines-murrine

CONFIGURE_ARGS+=	--enable-all-themes

.include "../../graphics/icon-naming-utils/buildlink3.mk"
BUILDLINK_DEPMETHOD.gdk-pixbuf2+=	build
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gtk2+=	build
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
