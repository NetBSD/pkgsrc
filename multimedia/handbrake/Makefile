# $NetBSD: Makefile,v 1.19.2.1 2012/10/03 12:08:54 spz Exp $
#

DISTNAME=	HandBrake-0.9.3
PKGNAME=	${DISTNAME:S/HandBrake/handbrake/}
PKGREVISION=	15
CATEGORIES=	multimedia
MASTER_SITES=	http://download.m0k.org/handbrake/releases/ \
		http://download.m0k.org/handbrake/contrib/

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

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl intltool msgfmt pkg-config bash
USE_TOOLS+=	autoconf automake aclocal autoreconf m4
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

BUILD_DEPENDS+=	jam>=2.5.2:../../devel/jam
BUILD_DEPENDS+=	nasm>=2.05.01:../../devel/nasm
BUILD_DEPENDS+=	yasm>=0.6.1:../../devel/yasm

CLI_CONFIGURE_ARGS=	--release

post-extract:
	cp ${FILESDIR}/patch-ffmpeg-nodocs.patch \
	    ${WRKSRC}/contrib/
.for distfile in ${CDISTFILES}
	cp ${DISTDIR}/${DIST_SUBDIR}/${distfile} \
	    ${WRKSRC}/contrib/${distfile:C/-.*//}.tar.gz
.endfor

pre-configure:
	cd ${WRKSRC}/gtk && ./autogen.sh

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
