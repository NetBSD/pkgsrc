# $NetBSD: Makefile,v 1.68 2020/06/01 06:13:03 rillig Exp $

DISTNAME=	wxsvg-1.5.20
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxsvg/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/wxsvg/
COMMENT=	C++ library to create, manipulate and render SVG files
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

GNU_CONFIGURE_WX_VERSION=	no

.include "../../graphics/libexif/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
