# $NetBSD: Makefile,v 1.79 2024/02/17 19:40:01 wiz Exp $

PKGNAME=	mencoder-${MPLAYER_VERSION}
PKGREVISION=	3

COMMENT=	Simple movie encoder for MPlayer-playable movies

USE_TOOLS+=	pkg-config

.include "../../multimedia/mplayer-share/Makefile.common"

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:tl} == "yes"
CONFIGURE_ARGS+=	--target=${MACHINE_ARCH:Q}-${OPSYS:Q}
# Reaching into the destdir with a -I flag to NATIVE_CC is kinda
# sleazy, but this will probably work and it saves the trouble of
# pulling in a gigantic tool dependency.
CONFIGURE_ARGS+=	--host-cc=${NATIVE_CC:Q}\ -I${_CROSS_DESTDIR:Q}${PREFIX:Q}/include/ffmpeg5
#TOOL_DEPENDS+=		ffmpeg5>=0:../../multimedia/ffmpeg5
#CONFIGURE_ARGS+=	--host-cc=${NATIVE_CC:Q}\ -I${TOOLBASE:Q}/include/ffmpeg5
.else
CONFIGURE_ARGS+=	--host-cc=${CC:Q}\ ${BUILDLINK_CPPFLAGS:Q}
.endif

# Fix build under Mac OS X, please see here for details:
# http://lists.mplayerhq.hu/pipermail/mplayer-dev-eng/2009-May/061515.html
LDFLAGS.Darwin+=	-framework Carbon

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

.include "../../multimedia/mplayer-share/depends.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
