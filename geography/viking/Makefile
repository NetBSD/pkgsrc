# $NetBSD: Makefile,v 1.93 2018/11/14 22:21:34 kleink Exp $
#

VERSION=		1.6.2
DISTNAME=		viking-${VERSION}
PKGREVISION=		20
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=viking/}${VERSION}/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		https://sourceforge.net/projects/viking/
COMMENT=		Viking manages GPS data, supports OpenStreetMap and geocaching

LICENSE=		gnu-gpl-v2

# C++11 is now required.
USE_LANGUAGES=		c c++

GNU_CONFIGURE=		yes

TEST_TARGET=		check

CONFIGURE_ARGS+=	--disable-magic

# Perhaps optionize use of gpsd (remove bl3, add this).
# CONFIGURE_ARGS+=	--disable-realtime-gps-tracking

CONFIGURE_ARGS+=	--disable-mapnik

# Building docs fails because mapnik being optional is not respected.
# For now, just omit docs until we have mapnik.
#CONFIGURE_ARGS+=	--enable-gtk-doc
#.include "../../textproc/gtk-doc/buildlink3.mk"

# According to upstream, gpsbabel is merely recommended.  gpsbabel is
# about to depend on qt5, and will thus become very large.  Users can
# install it and use it at runtime, so don't depend on it.
#DEPENDS+=		gpsbabel-[0-9]*:../../geography/gpsbabel

DEPENDS+=		p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
REPLACE_PERL=		viking-remote

USE_TOOLS+=		gmake intltool msgfmt pkg-config

.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/gexiv2/buildlink3.mk"
.include "../../geography/gpsd/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
