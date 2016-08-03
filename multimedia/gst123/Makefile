# $NetBSD: Makefile,v 1.32 2016/08/03 10:23:11 adam Exp $

DISTNAME=	gst123-0.3.3
PKGREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	http://space.twc.de/~stefan/gst123/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://space.twc.de/~stefan/gst123.php
COMMENT=	Flexible command line player based on gstreamer
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config gmake

USE_NCURSES=	yes
CONFIGURE_ARGS+=	NCURSES5_CONFIG=${BUILDLINK_PREFIX.ncurses}/bin/ncurses6-config

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
