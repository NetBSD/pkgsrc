# $NetBSD: Makefile,v 1.4 2026/04/20 18:44:42 vins Exp $

DISTNAME=	sndio-1.10.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.sndio.org/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	http://www.sndio.org/
COMMENT=	Small audio and MIDI framework
LICENSE=	isc

# Supporting any additional platform requires writing a -
# dedicated backend module for the sndio library.
#
BROKEN_EXCEPT_ON_PLATFORM=	OpenBSD-*-* FreeBSD-*-* \
				NetBSD-*-* Linux-*-*

HAS_CONFIGURE=	yes

BUILD_DEFS+=	VARBASE
SNDIO_HOME=	${VARBASE}/run/sndio

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"	# only needed for our rc.d script
DEPENDS+=	daemonize-[0-9]*:../../sysutils/daemonize
.endif

RCD_SCRIPTS=	sndio

PKG_USERS=		_sndio:_sndio
PKG_GROUPS=		_sndio
PKG_GECOS._sndio=	sndio user
PKG_SHELL._sndio=	${NOLOGIN}
PKG_HOME._sndio=	${SNDIO_HOME}

PKGCONFIG_OVERRIDE=		libsndio/sndio.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--mandir=${PREFIX}/${PKGMANDIR} \
			--pkgconfdir=${PREFIX}/lib/pkgconfig

.include "../../mk/oss.buildlink3.mk"

# support the right backend module
.if ${OSS_TYPE:tl} != "none"
SUBST_CLASSES+=         oss
SUBST_STAGE.oss=        pre-configure
SUBST_MESSAGE.oss=      Point to the correct OSS device.
SUBST_FILES.oss+=       libsndio/sio_oss.c
SUBST_SED.oss+=         -e "s,/dev/dsp,${DEVOSSAUDIO},g"
.elif ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif

BUILD_DIRS+=		libsndio sndiod sndioctl aucat midicat

.if ${OPSYS} == "Linux"
.  include "../../devel/libbsd/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
