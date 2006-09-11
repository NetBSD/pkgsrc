# $NetBSD: Makefile,v 1.54 2006/09/11 17:07:19 wiz Exp $
#

DISTNAME=		libgnomedb-1.9.103
CATEGORIES=		databases gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgnomedb/1.9/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome-db.org/
COMMENT=		GNOME2 database library

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

PKGCONFIG_OVERRIDE=	libgnomedb-2.0.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

GCONF2_SCHEMAS=		libgnomedb.schemas

.include "../../databases/libgda/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
