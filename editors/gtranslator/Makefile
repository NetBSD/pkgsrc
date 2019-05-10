# $NetBSD: Makefile,v 1.75 2019/05/10 13:14:18 wiz Exp $

DISTNAME=	gtranslator-2.91.6
PKGREVISION=	11
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtranslator/2.91/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Gtranslator
COMMENT=	Gettext po file editor for the GNOME desktop environment

BUILD_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
MANCOMPRESSED=		yes

CONFIGURE_ARGS+=	--enable-debug=no
CONFIGURE_ARGS+=	--enable-schemas-compile
CONFIGURE_ARGS+=	--disable-scrollkeeper

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/libgda/buildlink3.mk"
.include "../../devel/gdl/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"

#.include "../../mk/omf-scrollkeeper.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
