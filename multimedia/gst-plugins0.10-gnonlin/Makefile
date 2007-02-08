# $NetBSD: Makefile,v 1.1.1.1 2007/02/08 21:42:26 drochner Exp $
#

DISTNAME=	gnonlin-0.10.7
PKGNAME=	gst-gnonlin-0.10.7
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gnonlin/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gstreamer.freedesktop.org/modules/gnonlin.html
COMMENT=	Non-linear editing components for gstreamer

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
