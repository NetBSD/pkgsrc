# $NetBSD: Makefile,v 1.12 2018/11/14 22:21:43 kleink Exp $

PKGREVISION= 2
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-themes-3.22.16
CATEGORIES=	graphics
MASTER_SITES=	http://pub.mate-desktop.org/releases/themes/3.22/

COMMENT=	Icons and themes for MATE desktop

DEPENDS+=	gtk2-engines-[0-9]*:../../x11/gtk2-engines
DEPENDS+=	gtk2-engines-murrine>=0.98.0:../../x11/gtk2-engines-murrine

.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
