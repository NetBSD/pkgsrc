# $NetBSD: Makefile,v 1.35 2005/10/12 22:04:01 jmmv Exp $
#

DISTNAME=		yelp-2.10.0
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/yelp/2.10/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Help browser for GNOME 2 desktop

DEPENDS+=		docbook>=4.2:../../textproc/docbook
BUILD_USES_MSGFMT=	yes

BUILDLINK_DEPENDS.libxslt+=	libxslt>=1.1.4

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-html-widget=gtkhtml2

PKG_OPTIONS_VAR=	PKG_OPTIONS.yelp
.include "../../www/mozilla/gecko-options.mk"
.include "../../mk/bsd.options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../www/mozilla/gecko-depends.mk"

.include "../../mk/bsd.pkg.mk"
