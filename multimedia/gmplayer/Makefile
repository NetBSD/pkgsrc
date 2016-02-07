# $NetBSD: Makefile,v 1.131 2016/02/07 13:34:34 leot Exp $
#
# NOTE: if you are updating both mplayer and gmplayer, you must ensure
# that *both* distinfo files contain the correct, up-to-date files and
# checksums.
#
# NOTE: patches are shared between mplayer and gmplayer!
#

PKGNAME=	gmplayer-${MPLAYER_VERSION}

SKIN_SITES=	http://www1.mplayerhq.hu/MPlayer/skins/		\
		http://www2.mplayerhq.hu/MPlayer/skins/		\
		ftp://ftp1.mplayerhq.hu/MPlayer/skins/		\
		ftp://ftp2.mplayerhq.hu/MPlayer/skins/		\
		http://ftp5.mplayerhq.hu/MPlayer/skins/		\
		ftp://ftp5.mplayerhq.hu/MPlayer/skins/

.include "../../multimedia/mplayer-share/Makefile.common"
SKIN_EXTRACT_SUFX=	.tar.bz2

COMMENT=	Fast, cross-platform movie player with GTK2+ interface

SKINS+=		Abyss-1.7${SKIN_EXTRACT_SUFX}			\
		AlienMind-1.2${SKIN_EXTRACT_SUFX}		\
		Blue-1.11${SKIN_EXTRACT_SUFX}			\
		BlueHeart-1.5${SKIN_EXTRACT_SUFX}		\
		Blue-small-1.8${SKIN_EXTRACT_SUFX}		\
		Canary-1.2${SKIN_EXTRACT_SUFX}			\
		Clearlooks-1.7${SKIN_EXTRACT_SUFX}		\
		CornerMP-1.2${SKIN_EXTRACT_SUFX}		\
		CornerMP-aqua-1.4${SKIN_EXTRACT_SUFX}		\
		Corelian-1.2${SKIN_EXTRACT_SUFX}		\
		CubicPlayer-1.1${SKIN_EXTRACT_SUFX}		\
		Cyrus-1.2${SKIN_EXTRACT_SUFX}			\
		DVDPlayer-1.1${SKIN_EXTRACT_SUFX}		\
		Dushku-1.2${SKIN_EXTRACT_SUFX}			\
		ICY-1.0${SKIN_EXTRACT_SUFX}			\
		Industrial-1.0${SKIN_EXTRACT_SUFX}		\
		JiMPlayer-1.4${SKIN_EXTRACT_SUFX}		\
		KDE-0.3${SKIN_EXTRACT_SUFX}			\
		Linea-1.0${SKIN_EXTRACT_SUFX}			\
		MidnightLove-1.6${SKIN_EXTRACT_SUFX}		\
		OSX-Brushed-2.3${SKIN_EXTRACT_SUFX}		\
		OSX-Mod-1.1${SKIN_EXTRACT_SUFX}			\
		OpenDoh-1.1${SKIN_EXTRACT_SUFX}			\
		Orange-1.3${SKIN_EXTRACT_SUFX}			\
		PowerPlayer-1.1${SKIN_EXTRACT_SUFX}		\
		QPlayer-1.2${SKIN_EXTRACT_SUFX}			\
		QuickSilver-1.0${SKIN_EXTRACT_SUFX}		\
		Terminator3-1.1${SKIN_EXTRACT_SUFX}		\
		WMP6-2.2${SKIN_EXTRACT_SUFX}			\
		XFce4-1.0${SKIN_EXTRACT_SUFX}			\
		avifile-1.7${SKIN_EXTRACT_SUFX}			\
		bluecurve-1.3${SKIN_EXTRACT_SUFX}		\
		brushedGnome-1.1${SKIN_EXTRACT_SUFX}		\
		changuito-0.2${SKIN_EXTRACT_SUFX}		\
		clearplayer-0.9${SKIN_EXTRACT_SUFX}		\
		disappearer-1.2${SKIN_EXTRACT_SUFX}		\
		divxplayer-1.3${SKIN_EXTRACT_SUFX}		\
		gnome-1.1${SKIN_EXTRACT_SUFX}			\
		handheld-1.0${SKIN_EXTRACT_SUFX}		\
		hayraphon-1.0${SKIN_EXTRACT_SUFX}		\
		hwswskin-1.3${SKIN_EXTRACT_SUFX}		\
		iTunes-1.1${SKIN_EXTRACT_SUFX}			\
		iTunes-mini-1.1${SKIN_EXTRACT_SUFX}		\
		krystal-1.1${SKIN_EXTRACT_SUFX}			\
		mentalic-1.3${SKIN_EXTRACT_SUFX}		\
		mini-0.1${SKIN_EXTRACT_SUFX}			\
		moonphase-1.0${SKIN_EXTRACT_SUFX}		\
		mplayer_red-1.1${SKIN_EXTRACT_SUFX}		\
		nativeRed-1.2${SKIN_EXTRACT_SUFX}		\
		netscape4-1.0${SKIN_EXTRACT_SUFX}		\
		neutron-1.6${SKIN_EXTRACT_SUFX}			\
		new-age-1.0${SKIN_EXTRACT_SUFX}			\
		pcland-1.0${SKIN_EXTRACT_SUFX}			\
		phony-1.2${SKIN_EXTRACT_SUFX}			\
		plastic-1.3${SKIN_EXTRACT_SUFX}			\
		plastik-2.0${SKIN_EXTRACT_SUFX}			\
		productive-1.0${SKIN_EXTRACT_SUFX}		\
		proton-1.2${SKIN_EXTRACT_SUFX}			\
		sessene-1.0${SKIN_EXTRACT_SUFX}			\
		slim-1.3${SKIN_EXTRACT_SUFX}			\
		smoothwebby-1.1${SKIN_EXTRACT_SUFX}		\
		softgrip-1.2${SKIN_EXTRACT_SUFX}		\
		standard-1.11${SKIN_EXTRACT_SUFX}		\
		trium-1.4${SKIN_EXTRACT_SUFX}			\
		tvisor-1.2${SKIN_EXTRACT_SUFX}			\
		ultrafina-1.1${SKIN_EXTRACT_SUFX}		\
		webby-1.3${SKIN_EXTRACT_SUFX}			\
		xanim-1.7${SKIN_EXTRACT_SUFX}			\
		xine-lcd-1.2${SKIN_EXTRACT_SUFX}		\
		xmmplayer-1.5${SKIN_EXTRACT_SUFX}

.for skin in ${SKINS}
SITES.${skin}= ${SKIN_SITES}
.endfor

DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${SKINS}
DISTINFO_FILE=	${.CURDIR}/distinfo
DIST_SUBDIR=	mplayer

USE_TOOLS+=		pax pkg-config
CONFIGURE_ARGS+=	--enable-gui --disable-mencoder \
			--confdir=${PREFIX}/share/mplayer
CONFIGURE_ARGS+=	--enable-xvmc

INSTALLATION_DIRS=	bin share/mplayer/skins

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${DESTDIR}${PREFIX}/bin/gmplayer
.for skin in ${SKINS}
	( cd ${WRKDIR} && \
		${PAX} -rw ${skin:C/-[0-9]+.[0-9]+${SKIN_EXTRACT_SUFX}//} \
		    ${DESTDIR}${PREFIX}/share/mplayer/skins \
	)
.endfor
	${CHMOD} -R a+rX ${DESTDIR}${PREFIX}/share/mplayer/skins
	${RM} -f ${DESTDIR}${PREFIX}/share/mplayer/skins/default
	${LN} -s Blue ${DESTDIR}${PREFIX}/share/mplayer/skins/default
	${RM} -rf ${DESTDIR}${PREFIX}/share/mplayer/skins/Blue/.svn
	${RM} -rf ${DESTDIR}${PREFIX}/share/mplayer/skins/Blue/icons/.svn
	${RM} -f ${DESTDIR}${PREFIX}/share/mplayer/skins/disappearer/volume/generate_pot.c
	${RM} -f ${DESTDIR}${PREFIX}/share/mplayer/skins/disappearer/volume/make.sh
	${RM} -f ${DESTDIR}${PREFIX}/share/mplayer/skins/disappearer/volume/spec

.include "../../devel/glib2/buildlink3.mk"
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
