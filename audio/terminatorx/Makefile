# $NetBSD: Makefile,v 1.4 2006/01/24 07:31:55 wiz Exp $
#

DISTNAME=	terminatorX-3.82
PKGNAME=	${DISTNAME:S/X/x/}
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://terminatorx.cx/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://terminatorx.cx/
COMMENT=	Realtime audio synthesizer

DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123
DEPENDS+=	sox-[0-9]*:../../audio/sox
DEPENDS+=	vorbis-tools-[0-9]*:../../audio/vorbis-tools

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBS+=			${LIBOSSAUDIO}
CONFIGURE_ARGS+=	--disable-alsa

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	post-patch
SUBST_FILES.oss=	src/tX_global.c
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.oss=	"Fixing hardcoded audio device."

.include "../../audio/ladspa/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
