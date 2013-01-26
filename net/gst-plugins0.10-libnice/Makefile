# $NetBSD: Makefile,v 1.14 2013/01/26 21:38:32 adam Exp $
#

DISTNAME=	libnice-0.1.2
PKGNAME=	gst-plugins0.10-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	net devel
MASTER_SITES=	http://nice.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nice.freedesktop.org/wiki/
COMMENT=	IETF's draft Interactice Connectivity Establishment standard implementation
LICENSE=	gnu-lgpl-v2.1 OR mpl-1.1

PATCHDIR=	${.CURDIR}/../../net/libnice/patches
DISTINFO_FILE=	${.CURDIR}/../../net/libnice/distinfo

CONFLICTS+=	libnice<0.0.13

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
CONFIGURE_ARGS+= --with-gstreamer

BUILD_DIRS=	gst
INSTALL_DIRS=	gst

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/gupnp-igd/buildlink3.mk"
.include "../../net/libnice/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
