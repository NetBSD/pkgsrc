# $NetBSD: Makefile,v 1.8 2007/08/08 03:00:39 wulf Exp $

PKGNAME=	gnuradio-audio-oss-${VERSION}
COMMENT=	Open Sound System support for GNU Radio

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONF_FILES+=	${EGDIR}/gr-audio-oss.conf ${PKG_SYSCONFDIR}/gr-audio-oss.conf
CONFIGURE_ARGS+=--enable-gr-audio-oss

PYTHON_PATCH_SCRIPTS+=	gr-audio-oss/src/qa_oss.py
LDFLAGS = -lgnuradio-core

.include "../../mk/oss.buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
