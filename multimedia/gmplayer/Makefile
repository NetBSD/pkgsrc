# $NetBSD: Makefile,v 1.34 2005/05/16 01:15:32 jlam Exp $

#
# NOTE: if you are updating both mplayer and gmplayer, you must ensure
# that *both* distinfo files contain the correct, up-to-date files and
# checksums.
#
# NOTE: patches are shared between mplayer and gmplayer!
#

PKGNAME=	gmplayer-${MPLAYER_PKG_VERSION}

SKIN_SITES=	http://www.mplayerhq.hu/MPlayer/Skin/		\
		ftp://ftp.mplayerhq.hu/MPlayer/Skin/		\
		ftp://ftp.lug.udel.edu/MPlayer/Skin/		\
		ftp://ftp.freebsd.org/pub/FreeBSD/ports/distfiles/mplayer/ \
		${MASTER_SITE_LOCAL:=mplayer}

.include "../../multimedia/mplayer-share/Makefile.common"

COMMENT=	Software only MPEG-1/2/4 video decoder with a GTK+ interface

SKINS +=	AlienMind-1.2${EXTRACT_SUFX}			\
		Blue-1.4${EXTRACT_SUFX}				\
		BlueHeart-1.5${EXTRACT_SUFX}			\
		CornerMP-1.2${EXTRACT_SUFX}			\
		CornerMP-aqua-1.4${EXTRACT_SUFX}		\
		Cyrus-1.2${EXTRACT_SUFX}			\
		MidnightLove-1.6${EXTRACT_SUFX}			\
		WMP6-2.2${EXTRACT_SUFX}				\
		avifile-1.6${EXTRACT_SUFX}			\
		gnome-1.1${EXTRACT_SUFX}			\
		hayraphon-1.0${EXTRACT_SUFX}			\
		hwswskin-1.1${EXTRACT_SUFX}			\
		mentalic-1.2${EXTRACT_SUFX}			\
		neutron-1.5${EXTRACT_SUFX}			\
		phony-1.1${EXTRACT_SUFX}			\
		plastic-1.2${EXTRACT_SUFX}			\
		proton-1.2${EXTRACT_SUFX}			\
		slim-1.2${EXTRACT_SUFX}				\
		xanim-1.6${EXTRACT_SUFX}			\
		xine-lcd-1.2${EXTRACT_SUFX}

.if !defined(SITES_AlienMind-1.2.tar.bz2)
.  for skin in ${SKINS}
SITES_${skin}= ${SKIN_SITES}
.  endfor
.endif

DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${SKINS}
DISTINFO_FILE=	${.CURDIR}/distinfo
DIST_SUBDIR=	${PKGNAME_NOREV}-20050409

PKGSRC_USE_TOOLS+=	gtar
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
	@${RM} -f ${PREFIX}/share/mplayer/Skin/default
	${LN} -s Blue ${PREFIX}/share/mplayer/Skin/default

.include "../../multimedia/mplayer-share/Makefile.depends"

.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
.include "../../multimedia/mplayer-share/Makefile.cflags"
