# $NetBSD: Makefile,v 1.9 2004/04/19 22:23:02 xtraeme Exp $

PKGNAME=	gmplayer-${MPLAYER_PKG_VERSION}
PKGREVISION=	5

SKIN_SITES=	http://www.mplayerhq.hu/MPlayer/Skin/		\
		ftp://ftp.mplayerhq.hu/MPlayer/Skin/		\
		ftp://ftp.lug.udel.edu/MPlayer/Skin/		\
		ftp://ftp.freebsd.org/pub/FreeBSD/ports/distfiles/mplayer/ \
		http://distro.ibiblio.org/pub/linux/distributions/sorcerer/sources/MPlayer,Skin-AlienMind/1.1/ \
		${MASTER_SITE_LOCAL:=mplayer}

.include "../../multimedia/mplayer-share/Makefile.common"

COMMENT=	Software only MPEG-1/2/4 video decoder with a GTK+ interface

SKINS +=	default-1.7${EXTRACT_SUFX}			\
		AlienMind-1.1${EXTRACT_SUFX}			\
		BlueHeart-1.4${EXTRACT_SUFX}			\
		CornerMP-1.0${EXTRACT_SUFX}			\
		CornerMP-aqua-1.0${EXTRACT_SUFX}		\
		Cyrus-1.0${EXTRACT_SUFX}			\
		MidnightLove-1.5${EXTRACT_SUFX}			\
		WindowsMediaPlayer6-1.2${EXTRACT_SUFX}		\
		avifile-1.5${EXTRACT_SUFX}			\
		gnome-1.1${EXTRACT_SUFX}			\
		hayraphon-1.0${EXTRACT_SUFX}			\
		hwswskin-1.0${EXTRACT_SUFX}			\
		mentalic-1.1${EXTRACT_SUFX}			\
		neutron-1.4${EXTRACT_SUFX}			\
		phony-1.0${EXTRACT_SUFX}			\
		plastic-1.1.1${EXTRACT_SUFX}			\
		proton-1.1${EXTRACT_SUFX}			\
		slim-1.0${EXTRACT_SUFX}				\
		xanim-1.5${EXTRACT_SUFX}			\
		xine-lcd-1.0${EXTRACT_SUFX}

.if !defined(SITES_default-1.7.tar.bz2)
.  for skin in ${SKINS}
SITES_${skin}= ${SKIN_SITES}
.  endfor
.endif

DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${SKINS}

USE_BUILDLINK3=		YES
CONFIGURE_ARGS+=	--enable-gui --disable-mencoder \
			--confdir=${PREFIX}/share/mplayer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${PREFIX}/bin/gmplayer
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer/Skin
.for SKIN in ${SKINS}
	@${ECHO_MSG} "Installing skin ${SKIN}..."
	@${BZCAT} ${DISTDIR}/${DIST_SUBDIR}/${SKIN} |	\
	  ${GTAR} xCmf ${PREFIX}/share/mplayer/Skin -
.endfor
	@${CHMOD} -R a+r ${PREFIX}/share/mplayer/Skin
	@${CHMOD} a+rx ${PREFIX}/share/mplayer/Skin/*

.include "../../multimedia/mplayer-share/Makefile.depends"

.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
.include "../../multimedia/mplayer-share/Makefile.cflags"
