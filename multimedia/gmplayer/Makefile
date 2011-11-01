# $NetBSD: Makefile,v 1.94 2011/11/01 06:02:11 sbd Exp $

#
# NOTE: if you are updating both mplayer and gmplayer, you must ensure
# that *both* distinfo files contain the correct, up-to-date files and
# checksums.
#
# NOTE: patches are shared between mplayer and gmplayer!
#

PKGNAME=	gmplayer-${MPLAYER_VERSION}
PKGREVISION=	10

SKIN_SITES=	http://www1.mplayerhq.hu/MPlayer/skins/		\
		http://www2.mplayerhq.hu/MPlayer/skins/		\
		ftp://ftp1.mplayerhq.hu/MPlayer/skins/		\
		ftp://ftp2.mplayerhq.hu/MPlayer/skins/		\
		http://ftp5.mplayerhq.hu/MPlayer/skins/		\
		ftp://ftp5.mplayerhq.hu/MPlayer/skins/		\

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/mplayer-share/Makefile.common"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=		yasm-[0-9]*:../../devel/yasm
.endif

COMMENT=	Fast, cross-platform movie player with GTK2+ interface

SKINS +=	AlienMind-1.2${EXTRACT_SUFX}			\
		Blue-1.7${EXTRACT_SUFX}				\
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
DIST_SUBDIR=	mplayer

USE_TOOLS+=		gtar pkg-config
CONFIGURE_ARGS+=	--enable-gui --disable-mencoder \
			--confdir=${PREFIX}/share/mplayer
CONFIGURE_ARGS+=	--enable-xvmc

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${DESTDIR}${PREFIX}/bin/gmplayer
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/mplayer/Skin
.for skin in ${SKINS}
	@${ECHO_MSG} "Installing skin ${skin}..."
	${BZCAT} ${DISTDIR}/${DIST_SUBDIR}/${skin} |	\
	  ${GTAR} xCmf ${DESTDIR}${PREFIX}/share/mplayer/Skin -
.endfor
	${CHMOD} -R a+r ${DESTDIR}${PREFIX}/share/mplayer/Skin
	${CHMOD} a+rx ${DESTDIR}${PREFIX}/share/mplayer/Skin/*
	${RM} -f ${DESTDIR}${PREFIX}/share/mplayer/Skin/default
	${LN} -s Blue ${DESTDIR}${PREFIX}/share/mplayer/Skin/default
	${RM} -rf ${DESTDIR}${PREFIX}/share/mplayer/Skin/Blue/.svn
	${RM} -rf ${DESTDIR}${PREFIX}/share/mplayer/Skin/Blue/icons/.svn

.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"

.include "../../multimedia/mplayer-share/Makefile.depends"

.include "../../mk/bsd.pkg.mk"
.include "../../multimedia/mplayer-share/Makefile.cflags"
