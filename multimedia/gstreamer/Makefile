# $NetBSD: Makefile,v 1.8 2004/04/01 12:26:12 tron Exp $
#

DISTNAME=		gstreamer-0.6.4
PKGREVISION=		2
CATEGORIES=		multimedia gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gstreamer/0.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gstreamer.net/
COMMENT=		GNOME multimedia streamer library

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_PERL5=		build

CONFIGURE_ARGS+=	--disable-plugin-builddir

LIBTOOL_OVERRIDE+=	libtool libs/ext/cothreads/libtool

PKGCONFIG_OVERRIDE+=	libs/ext/cothreads/cothreads.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-control.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer.pc.in

PYTHON_VERSIONS_ACCEPTED=	23 23pth 22 22pth

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
