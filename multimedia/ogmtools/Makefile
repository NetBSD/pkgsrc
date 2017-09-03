# $NetBSD: Makefile,v 1.14 2017/09/03 08:53:11 wiz Exp $
#

DISTNAME=	ogmtools-1.5
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://www.bunkus.org/videotools/ogmtools/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.bunkus.org/videotools/ogmtools/
COMMENT=	Ogg Media files manipulation tools

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-dvdread-includes=${BUILDLINK_DIR:Q}
CPPFLAGS.SunOS+=	-Du_int16_t=uint16_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
