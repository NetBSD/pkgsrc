# $NetBSD: Makefile,v 1.14 2004/02/16 15:06:19 jmmv Exp $
#

DISTNAME=		yelp-2.4.2
PKGREVISION=		6
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/yelp/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Help browser for GNOME 2 desktop

DEPENDS=		gnome2-dirs>=1.4:../../misc/gnome2-dirs
DEPENDS+=		docbook>=4.2:../../textproc/docbook
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-html-widget=gtkhtml2

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/libgtkhtml/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
