# $NetBSD: Makefile,v 1.7 2004/03/13 11:17:43 abs Exp $
#

DISTNAME=	ogmtools-1.2
PKGREVISION=	1
CATEGORIES=	graphics audio
MASTER_SITES=	http://www.bunkus.org/videotools/ogmtools/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.bunkus.org/videotools/ogmtools/
COMMENT=	Ogg Media files manipulation tools

USE_BUILDLINK2=	YES
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-dvdread-includes=${BUILDLINK_DIR}

.include "../../audio/libvorbis/buildlink2.mk"
.include "../../multimedia/libdvdread/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
