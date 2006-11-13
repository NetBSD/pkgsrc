# $NetBSD: Makefile,v 1.1.1.1 2006/11/13 16:25:32 wulf Exp $

PKGNAME=	gnuradio-audio-jack-${VERSION}
COMMENT=	GNU Radio module for jack low latency audio server

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONF_FILES+=    ${EGDIR}/gr-audio-jack.conf ${PKG_SYSCONFDIR}/gr-audio-jack.conf
CONFIGURE_ARGS+=--enable-gr-audio-jack

PYTHON_PATCH_SCRIPTS+=	gr-audio-jack/src/python/qa_jack.py

.include "../../audio/jack/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
