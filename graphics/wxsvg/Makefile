# $NetBSD: Makefile,v 1.63 2018/11/14 22:21:47 kleink Exp $

DISTNAME=	wxsvg-1.5.3
PKGREVISION=	13
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

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../multimedia/ffmpeg1/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
