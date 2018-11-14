# $NetBSD: Makefile,v 1.48 2018/11/14 22:22:06 kleink Exp $
#

DISTNAME=	HandBrake-0.9.3
PKGNAME=	${DISTNAME:S/HandBrake/handbrake/}
PKGREVISION=	37
CATEGORIES=	multimedia
MASTER_SITES=	http://download.m0k.org/handbrake/releases/
MASTER_SITES+=	http://download.m0k.org/handbrake/contrib/
MASTER_SITES+=	${MASTER_SITE_FREEBSD:=handbrake/}

DIST_SUBDIR=	handbrake
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
CDISTFILES=	a52dec-0.7.4.tar.gz \
		bzip2-1.0.5.tar.gz \
		faac-1.26.tar.gz \
		faad2-2.6.1.tar.gz \
		ffmpeg-r15462.tar.gz \
		lame-3.98.tar.gz \
		libdca-r81-strapped.tar.gz \
		libdvdread-0.9.7.tar.gz \
		libmkv-0.6.3.tar.gz \
		libmp4v2-r45.tar.gz \
		libogg-1.1.3.tar.gz \
		libsamplerate-0.1.4.tar.gz \
		libtheora-1.0.tar.gz \
		libvorbis-aotuv_b5.tar.gz \
		mpeg2dec-0.5.1.tar.gz \
		mpeg4ip-1.3.tar.gz \
		libquicktime-0.9.10.tar.gz \
		x264-r1028-83baa7f.tar.gz \
		xvidcore-1.1.3.tar.gz \
		zlib-1.2.3.tar.gz
DISTFILES+=	${CDISTFILES}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://handbrake.fr/
COMMENT=	Multiplatform, multithreaded video transcoder

RESTRICTED=	Unresolved patent issues
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl intltool msgfmt pkg-config bash
USE_TOOLS+=	autoconf automake aclocal autoreconf m4
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

BUILD_DEPENDS+=	jam>=2.5.2:../../devel/jam
BUILD_DEPENDS+=	nasm>=2.05.01:../../devel/nasm
BUILD_DEPENDS+=	yasm>=0.6.1:../../devel/yasm
BUILD_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4

CLI_CONFIGURE_ARGS=	--release

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
	cp ${FILESDIR}/patch-ffmpeg-nodocs.patch \
	    ${WRKSRC}/contrib/
.for distfile in ${CDISTFILES}
	cp ${DISTDIR}/${DIST_SUBDIR}/${distfile} \
	    ${WRKSRC}/contrib/${distfile:C/-.*//}.tar.gz
.endfor

pre-configure:
	cd ${WRKSRC}/gtk && autoreconf -fi

do-configure:
	cd ${WRKSRC} && ./configure ${CLI_CONFIGURE_ARGS}
	cd ${WRKSRC}/gtk && ./configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && gmake
	cd ${WRKSRC}/gtk && gmake

do-install:
	cd ${WRKSRC}/gtk && gmake install DESTDIR=${DESTDIR}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../www/gtkhtml314/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
