# $NetBSD: Makefile,v 1.10 2008/07/14 12:56:06 joerg Exp $

PKGNAME=	gnuradio-audio-oss-${VERSION}
COMMENT=	Open Sound System support for GNU Radio

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONF_FILES+=	${EGDIR}/gr-audio-oss.conf ${PKG_SYSCONFDIR}/gr-audio-oss.conf
CONFIGURE_ARGS+=--enable-gr-audio-oss

PYTHON_PATCH_SCRIPTS+=	gr-audio-oss/src/qa_oss.py
LDFLAGS = -lgnuradio-core ${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}

.include "../../mk/oss.buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
