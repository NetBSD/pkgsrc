# $NetBSD: Makefile,v 1.45 2018/11/14 22:21:47 kleink Exp $

DISTNAME=	unicap-0.9.3
PKGREVISION=	39
CATEGORIES=	graphics
MASTER_SITES=	http://unicap-imaging.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://unicap-imaging.org/
COMMENT=	Uniform interface to video capture devices

USE_TOOLS+=		perl pkg-config gmake intltool msgfmt
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-v4l
CONFIGURE_ARGS+=	--disable-vid21394
CONFIGURE_ARGS+=	--enable-ucil-theora
#CONFIGURE_ARGS+=	--enable-ucil-avcodec

.if exists(/usr/include/sys/videoio.h)
CONFIGURE_ARGS+=	--enable-v4l2
.else
CONFIGURE_ARGS+=	--disable-v4l2
.endif

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
#.include "../../multimedia/ffmpeg1/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
