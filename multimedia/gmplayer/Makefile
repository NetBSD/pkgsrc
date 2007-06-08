# $NetBSD: Makefile,v 1.59.2.1 2007/06/08 11:50:25 ghen Exp $

#
# NOTE: if you are updating both mplayer and gmplayer, you must ensure
# that *both* distinfo files contain the correct, up-to-date files and
# checksums.
#
# NOTE: patches are shared between mplayer and gmplayer!
#

PKGNAME=	gmplayer-${MPLAYER_PKG_VERSION}
PKGREVISION=	2

BROKEN_IN=		pkgsrc-2006Q4

SKIN_SITES=	http://www1.mplayerhq.hu/MPlayer/skins/		\
		http://www2.mplayerhq.hu/MPlayer/skins/		\
		ftp://ftp1.mplayerhq.hu/MPlayer/skins/		\
		ftp://ftp2.mplayerhq.hu/MPlayer/skins/		\
		http://ftp5.mplayerhq.hu/MPlayer/skins/		\
		ftp://ftp5.mplayerhq.hu/MPlayer/skins/		\
		ftp://ftp.freebsd.org/pub/FreeBSD/ports/distfiles/mplayer/ \
		${MASTER_SITE_LOCAL:=mplayer/}

.include "../../multimedia/mplayer-share/Makefile.common"

COMMENT=	Software only MPEG-1/2/4 video decoder with a GTK+ interface

SKINS +=	AlienMind-1.2${EXTRACT_SUFX}			\
		Blue-1.6${EXTRACT_SUFX}				\
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
SITES.${skin}= ${SKIN_SITES}
.  endfor
.endif

DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${SKINS}
DISTINFO_FILE=	${.CURDIR}/distinfo
DIST_SUBDIR=	${PKGNAME_NOREV}-20060123

USE_TOOLS+=		gtar pkg-config
CONFIGURE_ARGS+=	--enable-gui --disable-mencoder \
			--confdir=${PREFIX}/share/mplayer

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${PREFIX}/bin/gmplayer
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer/Skin
.for skin in ${SKINS}
	@${ECHO_MSG} "Installing skin ${skin}..."
	${BZCAT} ${DISTDIR}/${DIST_SUBDIR}/${skin} |	\
	  ${GTAR} xCmf ${PREFIX}/share/mplayer/Skin -
.endfor
	${CHMOD} -R a+r ${PREFIX}/share/mplayer/Skin
	${CHMOD} a+rx ${PREFIX}/share/mplayer/Skin/*
	${RM} -f ${PREFIX}/share/mplayer/Skin/default
	${LN} -s Blue ${PREFIX}/share/mplayer/Skin/default
	${RM} -rf ${PREFIX}/share/mplayer/Skin/Blue/.svn
	${RM} -rf ${PREFIX}/share/mplayer/Skin/Blue/icons/.svn

.include "../../multimedia/mplayer-share/Makefile.depends"

.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
.include "../../multimedia/mplayer-share/Makefile.cflags"
