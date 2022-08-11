# $NetBSD: Makefile,v 1.82 2022/08/11 05:09:04 gutteridge Exp $

DISTNAME=		yelp-3.32.0
PKGREVISION=		13
CATEGORIES=		misc gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/yelp/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		prlw1@cam.ac.uk
HOMEPAGE=		https://www.gnome.org/
COMMENT=		Mallard capable help browser
LICENSE=		gnu-gpl-v2 AND apache-2.0

USE_TOOLS+=		gmake intltool msgfmt pkg-config itstool
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38.0
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.13.3
BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=1.1.4

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../textproc/yelp-xsl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
