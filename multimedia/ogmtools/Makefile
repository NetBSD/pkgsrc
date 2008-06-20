# $NetBSD: Makefile,v 1.10 2008/06/20 01:09:28 joerg Exp $
#

DISTNAME=	ogmtools-1.5
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.bunkus.org/videotools/ogmtools/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.bunkus.org/videotools/ogmtools/
COMMENT=	Ogg Media files manipulation tools

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-dvdread-includes=${BUILDLINK_DIR:Q}

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
