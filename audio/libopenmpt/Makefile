# $NetBSD: Makefile,v 1.75 2024/01/30 14:21:32 ryoon Exp $

DISTNAME=	libopenmpt-0.7.2+release.autotools
PKGNAME=	${DISTNAME:C/\+.*//}
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://lib.openmpt.org/files/libopenmpt/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lib.openmpt.org/libopenmpt/
COMMENT=	Library to decode tracked music files into a raw PCM audio stream
LICENSE=	modified-bsd

TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

USE_LANGUAGES=	c c++
USE_TOOLS=	gmake pkg-config

USE_CXX_FEATURES+=	charconv

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
