# $NetBSD: Makefile,v 1.73 2022/08/11 05:08:47 gutteridge Exp $

DISTNAME=	wxsvg-1.5.22
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxsvg/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/wxsvg/
COMMENT=	C++ library to create, manipulate and render SVG files
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libav
CONFIGURE_ARGS+=	--enable-render=cairo
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

GNU_CONFIGURE_WX_VERSION=	no

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
