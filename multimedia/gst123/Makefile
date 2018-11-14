# $NetBSD: Makefile,v 1.40 2018/11/14 22:22:06 kleink Exp $

DISTNAME=	gst123-0.3.5
PKGREVISION=	2
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
CONFIGURE_ARGS+=	NCURSES_CFLAGS=-I${BUILDLINK_PREFIX.ncurses}/include
CONFIGURE_ARGS+=	NCURSES_LIBS="-L${BUILDLINK_PREFIX.ncurses}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.ncurses}/lib -l${BUILDLINK_LIBNAME.ncurses}"

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
