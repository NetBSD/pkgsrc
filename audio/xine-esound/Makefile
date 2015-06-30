# $NetBSD: Makefile,v 1.41 2015/06/30 09:57:34 ryoon Exp $

.include "../../multimedia/xine-lib/Makefile.common"

PKGNAME=	${XINE_PKGNAME:S/lib/esound/}
PKGREVISION=	2
CATEGORIES=	audio
COMMENT=	The esound audio output plugin for xine-lib

DEPENDS+=	xine-lib>=1rc3a:../../multimedia/xine-lib

BUILD_DIRS=	src/audio_out
CONFIGURE_ARGS+=	--without-x --disable-xinerama
CONFIGURE_ARGS+=	--disable-vcd

INSTALLATION_DIRS=	lib/xine/plugins/${XINE_MOD_DIR_VER}

do-install:
	cd ${WRKSRC}/src/audio_out && \
		${LIBTOOL} --mode=install ${INSTALL_DATA} \
		xineplug_ao_out_esd.la \
		${DESTDIR}${PREFIX}/lib/xine/plugins/${XINE_MOD_DIR_VER}

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
