# $NetBSD: Makefile,v 1.23 2002/04/30 15:10:00 veego Exp $

.include "Makefile.common"

PKGNAME=	mplayer-${MPLAYER_PKG_VERSION}
COMMENT=	Software only MPEG-1/2/4 video decoder

MASTER_SITES+=	http://www2.mplayerhq.hu/MPlayer/releases/	\
		ftp://ftp.mplayerhq.hu/MPlayer/releases/	\
		ftp://ftp2.mplayerhq.hu/MPlayer/releases/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/DOCS/mplayer.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer
	${INSTALL_DATA} ${WRKSRC}/etc/codecs.conf ${PREFIX}/share/mplayer
	${CP} -R ${WRKSRC}/DOCS ${PREFIX}/share/mplayer

.include "../../audio/lame/buildlink.mk"
.include "../../devel/SDL/buildlink.mk"
.include "../../devel/binutils/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../lang/gcc/Makefile.gcc"
.include "../../misc/libdvdread/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
