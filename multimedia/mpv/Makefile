# $NetBSD: Makefile,v 1.105 2020/04/07 13:47:04 ryoon Exp $

DISTNAME=	mpv-0.32.0
PKGREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=mpv-player/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://mpv.io/
COMMENT=	Video player based on MPlayer and mplayer2
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

# needs sem_timedwait(3)
NOT_FOR_PLATFORM=	NetBSD-[1-6].*-*

NOT_PAX_MPROTECT_SAFE+=	bin/mpv

TOOL_DEPENDS+=	${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils
# ${WRKSRC}/bootstrap.py mentions needed version
TOOL_DEPENDS+=	waf>=2.0.9:../../devel/waf

WAF_REPLACE_EXECUTABLE=	yes
WAF_CONFIGURE_ARGS+=	--bindir=${PREFIX}/bin
WAF_CONFIGURE_ARGS+=	--enable-dvdnav
WAF_CONFIGURE_ARGS+=	--disable-egl-x11

PYTHON_FOR_BUILD_ONLY=	yes

USE_TOOLS+=	perl pkg-config

MAKE_DIRS=		${PKG_SYSCONFDIR}/mpv
INSTALLATION_DIRS=	share/examples/mpv
CONF_FILES+=		share/examples/mpv/encoding-profiles.conf ${PKG_SYSCONFDIR}/mpv/encoding-profiles.conf

SUBST_CLASSES+=		audio
SUBST_SED.audio+=	-e "s,/dev/dsp,${DEVOSSAUDIO},"
SUBST_FILES.audio+=	audio/out/ao_oss.c stream/ai_oss.c
SUBST_STAGE.audio=	pre-configure
SUBST_MESSAGE.audio=	Fixing path to audio device.

SUBST_CLASSES+=		python
SUBST_SED.python+=	-e "s,python,python${PYVERSSUFFIX},"
SUBST_SED.python+=	-e "s,rst2man,rst2man-${PYVERSSUFFIX},"
SUBST_FILES.python+=	wscript
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Fix Python command names.

.include "../../mk/bsd.prefs.mk"

#
# At some point this should be consolidated into mk/platform/Darwin.mk, it is
# here temporarily while any issues are ironed out and it can be made generic
# for Swift handling.
#
# On newer macOS releases there are a couple of swift compat static libraries
# that need to be added to the search path.
#
.if ${OPSYS} == "Darwin"
XCODE_DIR!=			xcode-select -p 2>/dev/null || ${TRUE}
.  if exists(${XCODE_DIR}/usr/lib/swift/macosx)
BUILDLINK_PASSTHRU_DIRS+=	${XCODE_DIR}/usr/lib/swift/macosx
.  elif exists(${XCODE_DIR}/Toolchains/XcodeDefault.xctoolchain/usr/lib/swift/macosx)
BUILDLINK_PASSTHRU_DIRS+=	${XCODE_DIR}/Toolchains/XcodeDefault.xctoolchain/usr/lib/swift/macosx
.  endif
.endif

post-install:
	cd ${DESTDIR}${PREFIX} && ${MV} etc/mpv/encoding-profiles.conf share/examples/mpv

.include "options.mk"

LDFLAGS.NetBSD+=	-lossaudio
.include "../../mk/oss.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/waf/waf.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
