# $NetBSD: Makefile,v 1.44 2026/09/02 19:02:47 wiz Exp $

PKGREVISION= 14
.include "../../meta-pkgs/mate/Makefile.common"

VERSION=	3.22.24
DISTNAME=	mate-themes-${VERSION}
CATEGORIES=	graphics
MASTER_SITES=	http://pub.mate-desktop.org/releases/themes/${VERSION:R}/

COMMENT=	Icons and themes for MATE desktop

ICON_THEMES=	yes

DEPENDS+=	gtk2-engines-[0-9]*:../../x11/gtk2-engines
DEPENDS+=	gtk2-engines-murrine>=0.98.0:../../x11/gtk2-engines-murrine

.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
