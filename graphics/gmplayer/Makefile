# $NetBSD: Makefile,v 1.5.2.1 2002/06/23 18:46:24 jlam Exp $

.include "../../graphics/mplayer-share/Makefile.common"

PKGNAME=	gmplayer-${MPLAYER_PKG_VERSION}
SKIN_SITES=	http://www.mplayerhq.hu/MPlayer/Skin/		\
		http://www2.mplayerhq.hu/MPlayer/Skin/		\
		ftp://ftp.mplayerhq.hu/MPlayer/Skin/		\
		ftp://ftp2.mplayerhq.hu/MPlayer/Skin/

COMMENT=	Software only MPEG-1/2/4 video decoder with a GTK+ interface

SKINS +=	default${EXTRACT_SUFX}				\
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
		CornerMP${EXTRACT_SUFX}				\
		CornerMP-aqua${EXTRACT_SUFX}			\
		hwswskin${EXTRACT_SUFX}

.if !defined(SITES_default.tar.bz2)
.for skin in ${SKINS}
SITES_${skin}= ${SKIN_SITES}
.endfor
.endif

DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${SKINS}

CONFIGURE_ARGS+=	--enable-gui
CONFIGURE_ARGS+=	--disable-mencoder

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${PREFIX}/bin/gmplayer
	${LN} -s ${PREFIX}/man/man1/mplayer.1   ${PREFIX}/man/man1/gmplayer.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer/Skin
.for SKIN in ${SKINS}
	@${ECHO_MSG} "Installing skin ${SKIN}..."
	@${GTAR} xCzf ${PREFIX}/share/mplayer/Skin/ ${DISTDIR}/${DIST_SUBDIR}/${SKIN}
.endfor
	@${CHMOD} -R a+r ${PREFIX}/share/mplayer/Skin
	@${CHMOD} a+rx ${PREFIX}/share/mplayer/Skin/*

.include "../../audio/nas/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../graphics/mplayer-share/Makefile.depends"
.include "../../mk/bsd.pkg.mk"
