# $NetBSD: Makefile,v 1.5 2001/12/25 16:45:33 zuntum Exp $
#

DISTNAME=	MPlayer-0.18pre
PKGNAME=	mplayer-0.18.0.1
CATEGORIES=	graphics
MASTER_SITES=	http://zuntum.utech.lublin.pl/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	svs@ropnet.ru,zuntum@netbsd.org
HOMEPAGE=	http://mplayer.sourceforge.net/
COMMENT=	Software only MPEG-1/2/4 video decoder

ONLY_FOR_PLATFORM=	NetBSD-1.5[Y-Z]*-i386

DEPENDS+=	win32-codecs>=010122:../../graphics/win32-codecs
BUILD_DEPENDS+=	nasm>=0.98:../../devel/nasm

RESTRICTED=		"unsure of the license"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

USE_X11=		YES
USE_GMAKE=		YES
HAS_CONFIGURE=		YES

WRKSRC=			${WRKDIR}/MPlayer-0.18pre5

CONFIGURE_ARGS+=	--prefix="${PREFIX}"
CONFIGURE_ARGS+=	--with-extraincdir="${BUILDLINK_DIR}/include"
CONFIGURE_ARGS+=	--with-extralibdir="${BUILDLINK_DIR}/lib"
CONFIGURE_ARGS+=	--with-win32libdir="${LOCALBASE}/lib/win32"
#CONFIGURE_ARGS+=	--disable-gcc-checking
CONFIGURE_ARGS+=	--disable-css
CONFIGURE_ARGS+=	--disable-streaming 

post-patch:
	cd ${WRKSRC} && for i in TOOLS/audio-block.c TOOLS/audio-block2.c TOOLS/audio-select.c	\
		libao2/ao_oss.c mp3lib/test2.c libac3/test2.c; do				\
		${SED} "s,\/dev\/dsp,\/dev\/audio,g" $${i} >> $${i}.done;			\
		${MV} -f $${i}.done $${i};							\
	done;

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer
	${CP} -R ${WRKSRC}/DOCS ${PREFIX}/share/mplayer

.include "../../devel/SDL/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
