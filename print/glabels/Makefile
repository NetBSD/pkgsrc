# $NetBSD: Makefile,v 1.123 2022/06/28 11:35:28 wiz Exp $

DISTNAME=	glabels-3.4.1
PKGREVISION=	11
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glabels/3.4/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://glabels.org/
COMMENT=	Program for creating labels and business cards
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	intltool pkg-config perl gmake itstool
USE_TOOLS+=	msgfmt msgmerge xgettext

TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2

PKGCONFIG_OVERRIDE+=	libglabels/libglabels-3.0.pc.in
PKGCONFIG_OVERRIDE+=	libglbarcode/libglbarcode-3.0.pc.in

.include "../../devel/glib2/schemas.mk"
.include "../../converters/qrencode/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
