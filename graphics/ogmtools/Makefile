# $NetBSD: Makefile,v 1.2 2003/05/07 08:41:57 wiz Exp $
#

DISTNAME=	ogmtools-1.0.2
CATEGORIES=	graphics audio
MASTER_SITES=	http://www.bunkus.org/videotools/ogmtools/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://www.bunkus.org/videotools/ogmtools/
COMMENT=	Ogg Media files manipulation tools

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-dvdread-includes=${BUILDLINK_DIR}

.include "../../audio/libvorbis/buildlink2.mk"
.include "../../misc/libdvdread/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
