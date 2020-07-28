# $NetBSD: Makefile,v 1.36 2020/07/28 12:44:18 fcambus Exp $

DISTNAME=	libopenmpt-0.5.1+release.autotools
PKGNAME=	${DISTNAME:C/\+.*//}
CATEGORIES=	audio
MASTER_SITES=	https://lib.openmpt.org/files/libopenmpt/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lib.openmpt.org/libopenmpt/
COMMENT=	Library to decode tracked music files into a raw PCM audio stream
LICENSE=	modified-bsd

BUILD_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

USE_LANGUAGES=	c c++
USE_TOOLS=	gmake pkg-config

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	libmodplug/libmodplug.pc.in libopenmpt/libopenmpt.pc.in
CONFIGURE_ARGS+=	--without-portaudio
CONFIGURE_ARGS+=	--without-portaudiocpp

.include "options.mk"

.include "../../audio/mpg123/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
