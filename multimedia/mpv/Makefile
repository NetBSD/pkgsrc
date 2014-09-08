# $NetBSD: Makefile,v 1.1 2014/09/08 11:38:17 wiz Exp $

DISTNAME=	mpv-0.5.1
CATEGORIES=	multimedia
MASTER_SITES=	-https://github.com/mpv-player/mpv/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mpv.io/
COMMENT=	Video player based on MPlayer and mplayer2
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
# ${WRKSRC}/bootstrap.py mentions needed version
BUILD_DEPENDS+=	waf>=1.7.16:../../devel/waf

WAF_ENV=	PATH=${PATH:Q} CC=${CC:Q} CXX=${CXX:Q} PREFIX=${PREFIX} \
		CFLAGS=${CFLAGS:Q} \
		CXXFLAGS=${CXXFLAGS:Q} LINKFLAGS=${LDFLAGS:Q} DESTDIR=${DESTDIR}
WAF_ARGS=	--mandir=${PREFIX}/${PKGMANDIR}

PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-docutils

USE_TOOLS+=	perl pkg-config

.if defined(MAKE_JOBS)
WAF_ENV+=	JOBS=${MAKE_JOBS:Q}
.endif

MAKE_DIRS=		${PKG_SYSCONFDIR}/mpv
INSTALLATION_DIRS=	share/examples/mpv
CONF_FILES+=		share/examples/mpv/encoding-profiles.conf ${PKG_SYSCONFDIR}/mpv/encoding-profiles.conf

SUBST_CLASSES+=		audio
SUBST_SED.audio+=	-e "s,/dev/dsp,${DEVOSSAUDIO},"
SUBST_FILES.audio+=	stream/audio_in.c waftools/checks/custom.py wscript
SUBST_STAGE.audio=	pre-configure
SUBST_MESSAGE.audio=	Fixing path to audio device.

post-extract:
	cp ${PREFIX}/bin/waf ${WRKSRC}

do-configure:
	cd ${WRKSRC} && env ${WAF_ENV} ./waf ${WAF_ARGS} ${WAF_CONFIGURE_ARGS} configure

do-build:
	cd ${WRKSRC} && env ${WAF_ENV} ./waf ${WAF_ARGS}

do-install:
	cd ${WRKSRC} && env ${WAF_ENV} ./waf ${WAF_ARGS} install
	cd ${DESTDIR}${PREFIX} && ${MV} etc/mpv/encoding-profiles.conf share/examples/mpv

.include "options.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../multimedia/libass/buildlink3.mk"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
