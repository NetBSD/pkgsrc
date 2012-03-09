# $NetBSD: Makefile,v 1.7 2012/03/09 12:34:13 wiz Exp $

PKGNAME=	gnuradio-audio-portaudio-${VERSION}
PKGREVISION=	4
COMMENT=	GNU Radio module adding support for portaudio

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONF_FILES+=    ${EGDIR}/gr-audio-portaudio.conf ${PKG_SYSCONFDIR}/gr-audio-portaudio.conf
CONFIGURE_ARGS+=--enable-gr-audio-portaudio
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

PYTHON_PATCH_SCRIPTS+=	gr-audio-portaudio/src/qa_portaudio.py

.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
