# $NetBSD: Makefile,v 1.90 2023/01/29 21:17:18 ryoon Exp $

DISTNAME=	HandBrake-1.5.1-source
PKGNAME=	${DISTNAME:tl:S/-source//}
PKGREVISION=	9
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

RESTRICTED=		Unresolved patent issues
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

WRKSRC=		${WRKDIR}/${DISTNAME:S/-source//}

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake perl intltool msgfmt pkg-config bash
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

BUILD_DEPENDS+=		cmake-[0-9]*:../../devel/cmake
BUILD_DEPENDS+=		nasm>=2.05.01:../../devel/nasm
BUILD_DEPENDS+=		meson-[0-9]*:../../devel/meson

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-fheinous-gnu-extensions
.endif

.include "options.mk"

BROKEN_GETTEXT_DETECTION=	yes
GHB_LOCALES=	af co cs da de es eu fr he hr it ja ko nl no pl pt pt_BR ro ru si sk sl_SI sv th tr uk_UA zh_CN zh_TW

post-build:
	set -e; cd ${WRKSRC};							\
	for po in ${GHB_LOCALES}; do						\
		mo="../.destdir/usr/pkg/share/locale/$${po%%.po}/LC_MESSAGES" ;	\
		${MKDIR} $${mo} ; ${ECHO_N} "msgfmt $${po}:	" ;		\
		${SED} -e '/^"Project-Id-Version:/ s/PACKAGE VERSION/ghb 0.1/'	\
			gtk/po/$${po}.po | ${TOOLS_DIR}/bin/msgfmt -v -c -	\
						-o $${mo}/ghb.mo ;		\
	done

.include "../../audio/lame/buildlink3.mk"
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
.include "../../multimedia/dav1d/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/libass/buildlink3.mk"
.include "../../multimedia/libbluray/buildlink3.mk"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../multimedia/x264/buildlink3.mk"
.include "../../multimedia/x265/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
JPEG_ACCEPTED=	libjpeg-turbo
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
