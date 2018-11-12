# $NetBSD: Makefile,v 1.52 2018/11/12 03:51:45 ryoon Exp $

DISTNAME=	terminatorX-3.82
PKGNAME=	${DISTNAME:S/X/x/}
PKGREVISION=	34
CATEGORIES=	audio
MASTER_SITES=	http://terminatorx.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://terminatorx.org/
COMMENT=	Realtime audio synthesizer
LICENSE=	gnu-gpl-v2

DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123
DEPENDS+=	sox-[0-9]*:../../audio/sox
DEPENDS+=	vorbis-tools-[0-9]*:../../audio/vorbis-tools

USE_LANGUAGES=		c c++03
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

LIBS+=			${LIBOSSAUDIO}
CONFIGURE_ARGS+=	--disable-alsa

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_FILES.oss=	src/tX_global.c
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.oss=	Fixing hardcoded audio device.

.include "../../audio/ladspa/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
