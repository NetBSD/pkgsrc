# $NetBSD: Makefile,v 1.9 2001/12/26 01:00:15 zuntum Exp $

DISTNAME=	MPlayer-0.60pre1
PKGNAME=	mplayer-0.60.0.1
CATEGORIES=	graphics
MASTER_SITES=	http://mp.dev.hu/MPlayer/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	svs@ropnet.ru,zuntum@netbsd.org
HOMEPAGE=	http://www.mplayerhq.hu/
COMMENT=	Software only MPEG-1/2/4 video decoder

ONLY_FOR_PLATFORM=	NetBSD-1.5[Y-Z]*-i386

DEPENDS+=	win32-codecs>=010122:../../graphics/win32-codecs
BUILD_DEPENDS+=	nasm>=0.98:../../devel/nasm
REPLACE_BUILDLINK_PATTERNS+=	*.mak

RESTRICTED=		"unsure of the license"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

USE_X11=		YES
USE_GMAKE=		YES
HAS_CONFIGURE=		YES

WRKSRC=			${WRKDIR}/${DISTNAME}

CONFIGURE_ARGS+=	--prefix="${PREFIX}"
CONFIGURE_ARGS+=	--with-extraincdir="${BUILDLINK_DIR}/include"
CONFIGURE_ARGS+=	--with-extralibdir="${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--with-win32libdir="${LOCALBASE}/lib/win32"
CONFIGURE_ARGS+=	--disable-css

post-configure:
	${CP} ${FILESDIR}/vcd_read_nbsd.c ${WRKSRC}/libmpdemux/vcd_read_nbsd.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/DOCS/mplayer.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer
	${INSTALL_DATA} ${WRKSRC}/etc/codecs.conf ${PREFIX}/share/mplayer
	${CP} -R ${WRKSRC}/DOCS ${PREFIX}/share/mplayer

.include "../../audio/lame/buildlink.mk"
.include "../../devel/SDL/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
