# $NetBSD: Makefile,v 1.6 2011/11/17 13:31:37 obache Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/xine-lib/Makefile.common"

PKGNAME=	${XINE_PKGNAME:S/lib/pulse/}
CATEGORIES=	audio
COMMENT=	The PulseAudio output plugin for xine-lib

DEPENDS+=	xine-lib>=1rc3a:../../multimedia/xine-lib

BUILD_DIRS=	${WRKSRC}/src/audio_out
CONFIGURE_ARGS+=	--without-x

INSTALLATION_DIRS=	lib/xine/plugins/${XINE_MOD_DIR_VER}

do-install:
	cd ${WRKSRC}/src/audio_out && \
		${LIBTOOL} --mode=install ${INSTALL_DATA} \
		xineplug_ao_out_pulseaudio.la \
		${DESTDIR}${PREFIX}/lib/xine/plugins/${XINE_MOD_DIR_VER}

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
