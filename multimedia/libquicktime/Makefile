# $NetBSD: Makefile,v 1.19 2020/03/20 11:58:04 nia Exp $

DISTNAME=	libquicktime-1.2.4
PKGREVISION=	15
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libquicktime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libquicktime.sourceforge.net/
COMMENT=	Library for quicktime/avi/mp4 files
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-doxygen
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	libquicktime.pc.in

# option?
CONFIGURE_ARGS+=	--enable-gpl
.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/faac/buildlink3.mk"
.include "../../multimedia/x264-devel/buildlink3.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/ffmpeg1/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
#.include "../../multimedia/libdv/buildlink3.mk"
.include "../../multimedia/schroedinger/buildlink3.mk"
#.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
