# $NetBSD: Makefile,v 1.66 2016/02/07 13:34:34 leot Exp $

PKGNAME=	mencoder-${MPLAYER_VERSION}

COMMENT=	Simple movie encoder for MPlayer-playable movies

USE_TOOLS+=	pkg-config

.include "../../multimedia/mplayer-share/Makefile.common"

# Fix build under Mac OS X, please see here for details:
# http://lists.mplayerhq.hu/pipermail/mplayer-dev-eng/2009-May/061515.html
.if ${OPSYS} == "Darwin"
LDFLAGS+=	-framework Carbon
.endif

CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer

BUILD_TARGET=	mencoder

MANCOMPRESSED_IF_MANZ=	YES
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mencoder ${DESTDIR}${PREFIX}/bin
	if [ X"${MANZ}" = X"" ]; then \
		${LN} -s -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mplayer.1 \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mencoder.1; \
	else \
		${LN} -s -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mplayer.1.gz \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mencoder.1.gz; \
	fi

.include "../../multimedia/mplayer-share/Makefile.depends"

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
.include "../../multimedia/mplayer-share/Makefile.cflags"
