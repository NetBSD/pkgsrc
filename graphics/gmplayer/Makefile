# $NetBSD: Makefile,v 1.2 2002/04/22 11:45:51 rh Exp $

.include "../../graphics/mplayer/Makefile.common"

PKGNAME=		${DISTNAME:S/MP/gmp/}
MASTER_SITES+=		http://www.mplayerhq.hu/MPlayer/Skin/		\
			http://www2.mplayerhq.hu/MPlayer/releases/	\
			http://www2.mplayerhq.hu/MPlayer/Skin/		\
			ftp://ftp.mplayerhq.hu/MPlayer/releases/	\
			ftp://ftp.mplayerhq.hu/MPlayer/Skin/		\
			ftp://ftp2.mplayerhq.hu/MPlayer/releases/	\
			ftp://ftp2.mplayerhq.hu/MPlayer/Skin/
DIST_SUBDIR=		gmplayer

COMMENT=		Software only MPEG-1/2/4 video decoder with a GTK+ interface

SKINS +=		default${EXTRACT_SUFX}				\
			MidnightLove${EXTRACT_SUFX}			\
			avifile${EXTRACT_SUFX}				\
			BlueHeart${EXTRACT_SUFX}			\
			WindowsMediaPlayer6${EXTRACT_SUFX}		\
			xanim${EXTRACT_SUFX}				\
			neutron${EXTRACT_SUFX}				\
			plastic${EXTRACT_SUFX}				\
			Cyrus${EXTRACT_SUFX}				\
			xine-lcd${EXTRACT_SUFX}				\
			phony${EXTRACT_SUFX}				\
			mentalic${EXTRACT_SUFX}				\
			proton${EXTRACT_SUFX}				\
			slim${EXTRACT_SUFX}				\
			netscape4${EXTRACT_SUFX}			\
			CubicPlayer${EXTRACT_SUFX}			\
			AlienMind${EXTRACT_SUFX}			\
			CornerMP${EXTRACT_SUFX}

DISTFILES+=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		${SKINS}

CONFIGURE_ARGS+=	--enable-gui
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/gmplayer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${PREFIX}/bin/gmplayer
	${INSTALL_MAN} ${WRKSRC}/DOCS/mplayer.1 ${PREFIX}/man/man1/gmplayer.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/gmplayer
	${INSTALL_DATA} ${WRKSRC}/etc/codecs.conf ${PREFIX}/share/gmplayer
	${CP} -R ${WRKSRC}/DOCS ${PREFIX}/share/gmplayer
	${INSTALL_DATA_DIR} ${PREFIX}/share/gmplayer/Skin
.for SKIN in ${SKINS}
	@${ECHO_MSG} "Installing skin ${SKIN}..."
	@${GTAR} xCzf ${PREFIX}/share/gmplayer/Skin/ ${DISTDIR}/${DIST_SUBDIR}/${SKIN}
.endfor
	@${CHMOD} -R a+r ${PREFIX}/share/gmplayer/Skin
	@${CHMOD} a+rx ${PREFIX}/share/gmplayer/Skin/*

.include "../../audio/lame/buildlink.mk"
.include "../../devel/SDL/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../misc/libdvdread/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
