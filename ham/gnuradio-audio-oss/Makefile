# $NetBSD: Makefile,v 1.7 2006/11/13 16:34:45 wulf Exp $

PKGNAME=	gnuradio-audio-oss-${VERSION}
COMMENT=	Open Sound System support for GNU Radio

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONF_FILES+=	${EGDIR}/gr-audio-oss.conf ${PKG_SYSCONFDIR}/gr-audio-oss.conf
CONFIGURE_ARGS+=--enable-gr-audio-oss

PYTHON_PATCH_SCRIPTS+=	gr-audio-oss/src/qa_oss.py

.include "../../mk/oss.buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
