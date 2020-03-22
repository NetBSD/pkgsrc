# $NetBSD: Makefile,v 1.99 2020/03/22 08:58:17 nia Exp $

DISTNAME=		snd-20.2
CATEGORIES=		audio
MASTER_SITES=		https://ccrma.stanford.edu/software/snd/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://ccrma.stanford.edu/software/snd/
COMMENT=		Sound editor modelled loosely after Emacs
LICENSE=		esdl-license

DEPENDS+=		flac-[0-9]*:../../audio/flac
DEPENDS+=		mpg123-[0-9]*:../../audio/mpg123
DEPENDS+=		speex-[0-9]*:../../audio/speex
DEPENDS+=		vorbis-tools-[0-9]*:../../audio/vorbis-tools

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt pkg-config

BUILD_TARGET=		snd
MAKE_FILE=		makefile

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.prefs.mk"

# On NetBSD we use sunaudio.
.if ${OSS_TYPE} != "none" && ${OPSYS} != "NetBSD"
CONFIGURE_ARGS+=	--with-oss
LDFLAGS+=		${LIBOSSAUDIO}
.else
CONFIGURE_ARGS+=	--without-oss
.endif

.include "options.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
