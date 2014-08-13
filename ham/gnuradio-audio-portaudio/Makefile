# $NetBSD: Makefile,v 1.15 2014/08/13 10:57:36 adam Exp $

PKGNAME=	gnuradio-audio-portaudio-${VERSION}
PKGREVISION=	10
COMMENT=	GNU Radio module adding support for portaudio

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONF_FILES+=    ${EGDIR}/gr-audio-portaudio.conf ${PKG_SYSCONFDIR}/gr-audio-portaudio.conf
CONFIGURE_ARGS+=--enable-gr-audio-portaudio
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

REPLACE_PYTHON+=	gr-audio-portaudio/src/qa_portaudio.py

.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
