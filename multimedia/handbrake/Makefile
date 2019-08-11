# $NetBSD: Makefile,v 1.52 2019/08/11 13:22:03 wiz Exp $
#

DISTNAME=	HandBrake-1.2.2-source
PKGNAME=	${DISTNAME:tl:S/-source//}
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	https://download.handbrake.fr/releases/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://handbrake.fr/
COMMENT=	Multiplatform, multithreaded video transcoder
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	handbrake
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
CDISTFILES=	ffmpeg-4.1.tar.bz2 \
		libbluray-1.0.2.tar.bz2 \
		libdvdnav-6.0.0.tar.bz2 \
		libdvdread-6.0.0.tar.bz2 \
		libvpx-1.7.0.tar.gz \
		x265_2.9.tar.gz
DISTFILES+=	${CDISTFILES}

.for f in ${CDISTFILES}
SITES.${f}=	https://download.handbrake.fr/contrib/
.endfor

RESTRICTED=	Unresolved patent issues
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

WRKSRC=		${WRKDIR}/${DISTNAME:S/-source//}

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake perl intltool msgfmt pkg-config bash
USE_TOOLS+=	autoconf automake aclocal autoreconf m4
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl

CONFIGURE_ARGS+=	--prefix=${PREFIX}
BUILD_DIRS=		build
MAKE_FILE=		GNUmakefile
BUILD_TARGET=		# empty
BUILD_FLAGS+=		BUILDLINK_DIR=${BUILDLINK_DIR}

BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
BUILD_DEPENDS+=	nasm>=2.05.01:../../devel/nasm
#BUILD_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4

# harfbuzz, which is now separate from pango, installs a header file
# called hb.h, and the include path plopped out by autocrap causes it
# to be included instead of handbrake's own hb.h. Hack around it by
# changing the include name to point specifically at the right hb.h.
SUBST_CLASSES+=		inchack
SUBST_STAGE.inchack=	pre-configure
SUBST_FILES.inchack=	gtk/src/*.[ch]
SUBST_SED.inchack=	-e "/^.include \"hb\.h\"/s,hb,../../libhb/hb,"
SUBST_MESSAGE.inchack=	Working around harfbuzz header conflict.

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-fheinous-gnu-extensions
.endif

post-extract:
	${MKDIR} ${WRKSRC}/download
.for distfile in ${CDISTFILES}
	cp ${DISTDIR}/${DIST_SUBDIR}/${distfile} \
		${WRKSRC}/download/
.endfor

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../multimedia/libass/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../multimedia/x264-devel/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
