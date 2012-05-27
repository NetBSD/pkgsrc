# $NetBSD: Makefile,v 1.18 2012/05/27 17:00:49 marino Exp $

DISTNAME=	wolf-linux-1.33.x86
PKGNAME=	rtcw-1.33
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/wolf/linux/old/
EXTRACT_SUFX=	.run

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://games.activision.com/games/wolfenstein/
COMMENT=	Return to Castle Wolfenstein for Linux

RESTRICTED=		Size; the data set is much too big
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base

# This package needs DRI support.
NOT_FOR_PLATFORM=	NetBSD-*-*

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DIRS=	# empty
RTCWDIR=	${PREFIX}/lib/lokigames/rtcw
USE_TOOLS+=	gtar pax gzip
EXTRACT_CMD=	${SED} '1,178d' ${DOWNLOADED_DISTFILE} |		\
		${GZIP_CMD} -d | ${GTAR} -C ${WRKSRC} -xf -

pre-extract:
	${MKDIR} ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${RTCWDIR}
	${CHMOD} 755 ${WRKSRC}/Docs/PunkBuster
	${CHMOD} 644 ${WRKSRC}/main/mp_bin.pk3
	cd ${WRKSRC} && pax -rw -p am . ${DESTDIR}${RTCWDIR}

.include "../../mk/bsd.pkg.mk"
