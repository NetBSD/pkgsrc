# $NetBSD: Makefile,v 1.18 2012/08/29 11:22:15 obache Exp $

PKGNAME=	gnuradio-audio-oss-${VERSION}
PKGREVISION=	6
COMMENT=	Open Sound System support for GNU Radio

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONF_FILES+=	${EGDIR}/gr-audio-oss.conf ${PKG_SYSCONFDIR}/gr-audio-oss.conf
CONFIGURE_ARGS+=--enable-gr-audio-oss
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

PYTHON_PATCH_SCRIPTS+=	gr-audio-oss/src/qa_oss.py
#LDFLAGS = -lgnuradio-core ${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}

.include "../../mk/oss.buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
