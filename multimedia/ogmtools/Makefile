# $NetBSD: Makefile,v 1.1.1.1 2004/04/12 21:47:02 salo Exp $
#

DISTNAME=	ogmtools-1.3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.bunkus.org/videotools/ogmtools/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.bunkus.org/videotools/ogmtools/
COMMENT=	Ogg Media files manipulation tools

USE_BUILDLINK3=	YES
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-dvdread-includes=${BUILDLINK_DIR}

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libogg/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
