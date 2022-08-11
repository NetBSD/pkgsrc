# $NetBSD: Makefile,v 1.57 2022/08/11 05:08:05 gutteridge Exp $
#

DISTNAME=	gnome-chemistry-utils-0.14.16
PKGREVISION=	10
CATEGORIES=	biology
MASTER_SITES=	http://download-mirror.savannah.gnu.org/releases/gchemutils/0.14/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gchemutils.nongnu.org/
COMMENT=	GChemPaint, a 2D chemical editor and other programs
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config msgfmt xgettext msgmerge perl
USE_LANGUAGES=	c c++

BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-ldl

CONFIGURE_ARGS+=	--disable-update-databases

ICON_THEMES=	yes
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../misc/goffice0.10/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../biology/chemical-mime-data/buildlink3.mk"
.include "../../biology/bodr/buildlink3.mk"
.include "../../biology/openbabel/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
