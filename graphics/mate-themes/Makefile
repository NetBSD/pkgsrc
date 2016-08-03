# $NetBSD: Makefile,v 1.2 2016/08/03 10:22:54 adam Exp $

PKGREVISION= 1
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
