# $NetBSD: Makefile,v 1.3 2009/08/12 12:21:39 markd Exp $

PKGNAME=	gnuradio-audio-portaudio-${VERSION}
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
