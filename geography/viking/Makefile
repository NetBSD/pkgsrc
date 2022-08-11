# $NetBSD: Makefile,v 1.126 2022/08/11 05:08:38 gutteridge Exp $
#

VERSION=		1.10
DISTNAME=		viking-${VERSION}
PKGREVISION=		3
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=viking/}${VERSION}/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		https://sourceforge.net/projects/viking/
COMMENT=		Viking manages GPS data, supports OpenStreetMap and geocaching
LICENSE=		gnu-gpl-v2

TOOL_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

# viking says it "will" use c++11, and mapnik (not yet included) needs
# c++11.
USE_LANGUAGES=		c c++

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_TOOLS+=		itstool

GNU_CONFIGURE=		yes

TEST_TARGET=		check

# For each option, "\todo RESOLVE" means: Decide to make default, or
# to turn off, or to make an option, and explain why.

# \todo RESOLVE
CONFIGURE_ARGS+=	--disable-geoclue

# \todo RESOLVE
CONFIGURE_ARGS+=	--disable-magic

# \todo RESOLVE
CONFIGURE_ARGS+=	--disable-mapnik
# \todo README says icu is required.  However, it seems to be
# dependency of mapnik, not necessarily actually used by viking.

# \todo RESOLVE
CONFIGURE_ARGS+=	--disable-oauth

# \todo RESOLVE
CONFIGURE_ARGS+=	--disable-zip
#.include "../../archivers/libzip/buildlink3.mk"

# Perhaps optionize use of gpsd (remove bl3, add this).
# CONFIGURE_ARGS+=	--disable-realtime-gps-tracking

# Building docs fails with a unicode error.
# old: Building docs fails because mapnik being optional is not respected.
# \todo Resolve.
#CONFIGURE_ARGS+=	--enable-gtk-doc
#.include "../../textproc/gtk-doc/buildlink3.mk"

# According to upstream, gpsbabel is merely recommended.  gpsbabel
# depends on qt, and is thus really large.  Users can install it and
# use it at runtime, so don't depend on it at build time.
#DEPENDS+=		gpsbabel-[0-9]*:../../geography/gpsbabel

.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/gexiv2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../geography/gpsd/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
# Avoids internal MD5, and betterintegration with thumbmail cache.
.include "../../security/nettle/buildlink3.mk"
# gnome-doc-utils is needed even if not building documentation
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
