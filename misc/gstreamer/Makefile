# $NetBSD: Makefile,v 1.11 2003/12/13 00:45:24 wiz Exp $
#

DISTNAME=		gstreamer-0.6.1
PKGREVISION=		6
CATEGORIES=		misc gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gstreamer/0.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gstreamer.net/
COMMENT=		GNOME multimedia streamer library

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_GMAKE=		yes
USE_PERL5=		build

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libs/ext/cothreads/cothreads.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pkgconfig/gstreamer-control.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pkgconfig/gstreamer.pc.in

PYTHON_VERSIONS_ACCEPTED=	23 23pth 22 22pth

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
