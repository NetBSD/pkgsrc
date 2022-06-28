# $NetBSD: Makefile,v 1.162 2022/06/28 11:31:39 wiz Exp $

DISTNAME=	anjuta-3.34.0
PKGREVISION=	14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/anjuta/3.34/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.anjuta.org/
COMMENT=	GTK+ based IDE for C and C++
LICENSE=	gnu-gpl-v2

DEPENDS+=	autogen-[0-9]*:../../devel/autogen
DEPENDS+=	autoconf>=2.59:../../devel/autoconf
DEPENDS+=	automake>=1.8.2:../../devel/automake
DEPENDS+=	gsettings-desktop-schemas-[0-9]*:../../sysutils/gsettings-desktop-schemas
DEPENDS+=	libtool>=1.5.2:../../devel/libtool

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake:run intltool pkg-config:run perl:run sh:run
USE_TOOLS+=		msgfmt:run msgmerge:run xgettext:run
USE_TOOLS+=		bash:run bison flex itstool
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-schemas-compile
# Couldn't find include 'Gdl-3.gir'
CONFIGURE_ARGS+=	--enable-introspection=no

CONFIGURE_ARGS+=	--disable-plugin-subversion
# devhelp3 unavailable in pkgsrc currently
CONFIGURE_ARGS+=	--disable-plugin-devhelp

CONFIGURE_ARGS+=	--disable-plugin-vala

CONFIGURE_ARGS+=	YACC="bison -y"

REPLACE_SH+=		scripts/anjuta_import.sh.in
REPLACE_PERL+=		plugins/tools/scripts/*.pl scripts/*.pl
REPLACE_BASH+=		global-tags/create_global_tags.sh.in

BUILDLINK_TRANSFORM+=	rm:-Werror=format=2

.include "../../databases/libgda/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gdl/buildlink3.mk"
.include "../../devel/glade/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../x11/vte3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
