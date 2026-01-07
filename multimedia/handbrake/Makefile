# $NetBSD: Makefile,v 1.128 2026/01/07 08:48:08 wiz Exp $

DISTNAME=	HandBrake-1.10.0-source
PKGNAME=	${DISTNAME:tl:S/-source//}
PKGREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=HandBrake/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_PROJECT=	HandBrake
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://handbrake.fr/
COMMENT=	Multiplatform, multithreaded video transcoder
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	handbrake
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

# see contrib/libjpeg-turbo/module.defs for required version
LIBJPEG_TURBO=		libjpeg-turbo-3.1.1.tar.gz
EXTRA_FILES+=		${LIBJPEG_TURBO}
SITES.${LIBJPEG_TURBO}=	https://github.com/HandBrake/HandBrake-contribs/releases/download/contribs2/

FFMPEG=			ffmpeg-7.1.1.tar.bz2
EXTRA_FILES+=		${FFMPEG}
SITES.${FFMPEG}=	https://github.com/HandBrake/HandBrake-contribs/releases/download/contribs2/

X265=			x265-snapshot-20250729-13276.tar.gz
EXTRA_FILES+=		${X265}
SITES.${X265}=		https://github.com/HandBrake/HandBrake-contribs/releases/download/contribs2/

DISTFILES+=		${EXTRA_FILES}

RESTRICTED=		Unresolved patent issues
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/${DISTNAME:S/-source//}

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake sed perl intltool msgfmt pkg-config bash
USE_TOOLS+=	autoconf automake aclocal autoreconf m4
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

PYTHON_FOR_BUILD_ONLY?=	yes

BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl

PLIST_SRC+=	${PKGDIR}/PLIST

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--disable-xcode
CONFIGURE_ARGS+=	--enable-nls

MAKE_FILE=		GNUmakefile
BUILD_DIRS=		build
BUILD_TARGET=		# empty

TOOL_DEPENDS+=		cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=		nasm>=2.05.01:../../devel/nasm
TOOL_DEPENDS+=		meson-[0-9]*:../../devel/meson

LDFLAGS+=	-ldovi -L${PREFIX}/${BUILDLINK_PREFIX.libdovi}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libdovi}/lib

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-fheinous-gnu-extensions
.endif

.include "options.mk"

pre-build:
	${MKDIR} ${WRKSRC}/download
.for f in ${EXTRA_FILES}
	${LN} -fs ${DISTDIR}/${DIST_SUBDIR}/${f} \
		${WRKSRC}/download
.endfor

BROKEN_GETTEXT_DETECTION=	yes
GHB_LOCALES=	bg ca co de es eu fi fr it ja ko nl pt_BR sl_SI sv zh_CN

.PHONY: post-build-gtk4
post-build-gtk4:
	set -e; cd ${WRKSRC};							\
	for po in ${GHB_LOCALES}; do						\
		mo="../.destdir/usr/pkg/share/locale/$${po%%.po}/LC_MESSAGES" ;	\
		${MKDIR} $${mo} ; ${ECHO_N} "msgfmt $${po}:	" ;		\
		${SED} -e '/^"Project-Id-Version:/ s/PACKAGE VERSION/ghb 0.1/'	\
			gtk/po/$${po}.po | ${TOOLS_DIR}/bin/msgfmt -v -c -	\
						-o $${mo}/ghb.mo ;		\
	done

.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libdovi/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/zimg/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../multimedia/dav1d/buildlink3.mk"
#.include "../../multimedia/ffmpeg5/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/libass/buildlink3.mk"
.include "../../multimedia/libbluray/buildlink3.mk"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../multimedia/svt-av1/buildlink3.mk"
.include "../../multimedia/x264/buildlink3.mk"
#.include "../../multimedia/x265/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
