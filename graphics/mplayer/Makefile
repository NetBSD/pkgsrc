# $NetBSD: Makefile,v 1.21 2002/04/22 11:45:52 rh Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/MP/mp/}
PKGREVISION=	2
MASTER_SITES=	http://mp.dev.hu/MPlayer/releases/

COMMENT=	Software only MPEG-1/2/4 video decoder

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/DOCS/mplayer.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer
	${INSTALL_DATA} ${WRKSRC}/etc/codecs.conf ${PREFIX}/share/mplayer
	${CP} -R ${WRKSRC}/DOCS ${PREFIX}/share/mplayer

.include "../../audio/lame/buildlink.mk"
.include "../../devel/SDL/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../misc/libdvdread/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
