# $NetBSD: Makefile,v 1.62 2009/05/27 20:09:36 wiz Exp $
#

DISTNAME=	libgsf-1.14.14
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgsf/1.14/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME2 structured file library
LICENSE=	gnu-gpl-v2 # AND gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE=	libgsf-1.pc.in
PKGCONFIG_OVERRIDE+=	libgsf-gnome-1.pc.in

CONFIGURE_ARGS+=	--without-python

# XXX workaround for missing substitution in configure
MAKE_ENV+=	GCONF2_SCHEMAS_DIR=${GCONF_SCHEMAS_DIR}

GCONF_SCHEMAS=	gsf-office-thumbnailer.schemas

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../mk/bsd.pkg.mk"
