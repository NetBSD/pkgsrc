# $NetBSD: Makefile,v 1.102 2012/09/15 10:05:46 obache Exp $

#
# NOTE: if you are updating both mplayer and gmplayer, you must ensure
# that *both* distinfo files contain the correct, up-to-date files and
# checksums.
#
# NOTE: patches are shared between mplayer and gmplayer!
#

PKGNAME=	gmplayer-${MPLAYER_VERSION}
PKGREVISION=	3

SKIN_SITES=	http://www1.mplayerhq.hu/MPlayer/skins/		\
		http://www2.mplayerhq.hu/MPlayer/skins/		\
		ftp://ftp1.mplayerhq.hu/MPlayer/skins/		\
		ftp://ftp2.mplayerhq.hu/MPlayer/skins/		\
		http://ftp5.mplayerhq.hu/MPlayer/skins/		\
		ftp://ftp5.mplayerhq.hu/MPlayer/skins/

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/mplayer-share/Makefile.common"
SKIN_EXTRACT_SUFX=	.tar.bz2

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=		yasm-[0-9]*:../../devel/yasm
.endif

COMMENT=	Fast, cross-platform movie player with GTK2+ interface

SKINS+=		AlienMind-1.2${SKIN_EXTRACT_SUFX}		\
		Blue-1.7${SKIN_EXTRACT_SUFX}			\
		BlueHeart-1.5${SKIN_EXTRACT_SUFX}		\
		CornerMP-1.2${SKIN_EXTRACT_SUFX}		\
		CornerMP-aqua-1.4${SKIN_EXTRACT_SUFX}		\
		Cyrus-1.2${SKIN_EXTRACT_SUFX}			\
		MidnightLove-1.6${SKIN_EXTRACT_SUFX}		\
		WMP6-2.2${SKIN_EXTRACT_SUFX}			\
		avifile-1.6${SKIN_EXTRACT_SUFX}			\
		gnome-1.1${SKIN_EXTRACT_SUFX}			\
		hayraphon-1.0${SKIN_EXTRACT_SUFX}		\
		hwswskin-1.1${SKIN_EXTRACT_SUFX}		\
		mentalic-1.2${SKIN_EXTRACT_SUFX}		\
		neutron-1.5${SKIN_EXTRACT_SUFX}			\
		phony-1.1${SKIN_EXTRACT_SUFX}			\
		plastic-1.2${SKIN_EXTRACT_SUFX}			\
		proton-1.2${SKIN_EXTRACT_SUFX}			\
		slim-1.2${SKIN_EXTRACT_SUFX}			\
		xanim-1.6${SKIN_EXTRACT_SUFX}			\
		xine-lcd-1.2${SKIN_EXTRACT_SUFX}

.for skin in ${SKINS}
SITES.${skin}= ${SKIN_SITES}
.endfor

DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${SKINS}
DISTINFO_FILE=	${.CURDIR}/distinfo
DIST_SUBDIR=	mplayer

USE_TOOLS+=		gtar pkg-config
CONFIGURE_ARGS+=	--enable-gui --disable-mencoder \
			--confdir=${PREFIX}/share/mplayer
CONFIGURE_ARGS+=	--enable-xvmc

INSTALLATION_DIRS=	bin share/mplayer/skins

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${DESTDIR}${PREFIX}/bin/gmplayer
.for skin in ${SKINS}
	@${ECHO_MSG} "Installing skin ${skin}..."
	${BZCAT} ${DISTDIR}/${DIST_SUBDIR}/${skin} |	\
	  ${GTAR} xCmf ${DESTDIR}${PREFIX}/share/mplayer/skins -
.endfor
	${CHMOD} -R a+rX ${DESTDIR}${PREFIX}/share/mplayer/skins
	${RM} -f ${DESTDIR}${PREFIX}/share/mplayer/skins/default
	${LN} -s Blue ${DESTDIR}${PREFIX}/share/mplayer/skins/default
	${RM} -rf ${DESTDIR}${PREFIX}/share/mplayer/skins/Blue/.svn
	${RM} -rf ${DESTDIR}${PREFIX}/share/mplayer/skins/Blue/icons/.svn

.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"

.include "../../multimedia/mplayer-share/Makefile.depends"

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
.include "../../multimedia/mplayer-share/Makefile.cflags"
