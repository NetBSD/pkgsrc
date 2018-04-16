# $NetBSD: Makefile,v 1.9 2018/04/16 14:34:39 wiz Exp $

PKGREVISION= 3
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-themes-3.22.12
CATEGORIES=	graphics
MASTER_SITES=	http://pub.mate-desktop.org/releases/themes/3.22/

COMMENT=	Icons and themes for MATE desktop

DEPENDS+=	gtk2-engines-[0-9]*:../../x11/gtk2-engines
DEPENDS+=	gtk2-engines-murrine>=0.98.0:../../x11/gtk2-engines-murrine

CONFIGURE_ARGS+=	--enable-all-themes

.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
