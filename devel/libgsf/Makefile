# $NetBSD: Makefile,v 1.38 2006/06/15 16:54:56 joerg Exp $
#

DISTNAME=	libgsf-1.14.1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgsf/1.14/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME2 structured file library

USE_TOOLS+=		pkg-config gmake msgfmt
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE=	libgsf-1.pc.in
PKGCONFIG_OVERRIDE+=	libgsf-gnome-1.pc.in

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/libgsf

GCONF2_SCHEMAS=		gsf-office-thumbnailer.schemas

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../mk/bsd.pkg.mk"
