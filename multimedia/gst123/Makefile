# $NetBSD: Makefile,v 1.63 2026/01/27 08:40:16 wiz Exp $

DISTNAME=	gst123-0.3.5
PKGREVISION=	22
CATEGORIES=	multimedia
MASTER_SITES=	https://space.twc.de/~stefan/gst123/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://space.twc.de/~stefan/gst123.php
COMMENT=	Flexible command line player based on gstreamer
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config gmake

CONFIGURE_ARGS+=	NCURSES_CFLAGS=-I${BUILDLINK_PREFIX.ncurses}/include
CONFIGURE_ARGS+=	NCURSES_LIBS="-L${BUILDLINK_PREFIX.ncurses}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.ncurses}/lib -l${BUILDLINK_LIBNAME.ncurses}"

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
