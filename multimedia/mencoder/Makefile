# $NetBSD: Makefile,v 1.45 2009/10/18 22:22:11 ahoka Exp $

PKGNAME=	mencoder-${MPLAYER_VERSION}
#PKGREVISION=	0

COMMENT=	Simple movie encoder for MPlayer-playable movies

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/mplayer-share/Makefile.common"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=		yasm-[0-9]*:../../devel/yasm
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

.include "../../mk/bsd.pkg.mk"
.include "../../multimedia/mplayer-share/Makefile.cflags"
