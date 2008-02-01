# $NetBSD: Makefile,v 1.13 2008/02/01 02:34:21 dmcmahill Exp $

DISTNAME=		geda-gattrib-${PKGVERSION}
PKGNAME=		gattrib-${PKGVERSION}
CATEGORIES=		cad

MAINTAINER=		wulf@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Attribute editor for gEDA

.include "../../cad/geda/Makefile.common"

USE_TOOLS+=             bash intltool msgfmt pkg-config
REPLACE_BASH=		icon-theme-installer
GNU_CONFIGURE=		YES

.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
