# $NetBSD: Makefile,v 1.62 2018/11/14 22:22:04 kleink Exp $

DISTNAME=		yelp-3.22.0
PKGREVISION=		17
CATEGORIES=		misc gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/yelp/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		prlw1@cam.ac.uk
HOMEPAGE=		https://www.gnome.org/
COMMENT=		Mallard capable help browser
LICENSE=		gnu-gpl-v2 AND apache-2.0

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

BUILD_DEPENDS+=		itstool-[0-9]*:../../textproc/itstool

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38.0
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.13.3
BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=1.1.4

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../textproc/yelp-xsl/buildlink3.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
