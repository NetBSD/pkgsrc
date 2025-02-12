# $NetBSD: Makefile,v 1.66 2025/02/12 06:44:31 ryoon Exp $

PKGREVISION= 16
.include "../../multimedia/xine-lib/Makefile.common"

PKGNAME=	${XINE_PKGNAME:S/lib/pulse/}
CATEGORIES=	audio
COMMENT=	The PulseAudio output plugin for xine-lib

DEPENDS+=	xine-lib>=1rc3a:../../multimedia/xine-lib

BUILD_DIRS=		src/audio_out
CONFIGURE_ARGS+=	--without-x --disable-xinerama
CONFIGURE_ARGS+=	--disable-vcd
CONFIGURE_ARGS+=	--with-pulseaudio

INSTALLATION_DIRS=	lib/xine/plugins/${XINE_MOD_DIR_VER}

do-install:
	cd ${WRKSRC}/src/audio_out && \
		${LIBTOOL} --mode=install ${INSTALL_DATA} \
		xineplug_ao_out_pulseaudio.la \
		${DESTDIR}${PREFIX}/lib/xine/plugins/${XINE_MOD_DIR_VER}

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
