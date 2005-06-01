# $NetBSD: Makefile,v 1.31 2005/06/01 18:03:05 jlam Exp $
#

DISTNAME=		yelp-2.10.0
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
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-html-widget=gtkhtml2

.include "../../mk/bsd.prefs.mk"

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
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/libgtkhtml/buildlink3.mk"
.if ${GECKO_PROVIDER} == "firefox"
# firefox didn't have a pkgconfig file before 1.0.4
BUILDLINK_DEPENDS.firefox+= firefox>=1.0.4
.include "../../www/firefox/buildlink3.mk"
.else
.include "../../www/mozilla-gtk2/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
