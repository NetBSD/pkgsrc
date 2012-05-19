# $NetBSD: Makefile,v 1.17 2012/05/19 14:21:59 marino Exp $

DISTNAME=	wolf-linux-1.33.x86
PKGNAME=	rtcw-1.33
PKGREVISION=	1
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
USE_TOOLS+=	gtar pax
EXTRACT_CMD=	${SED} '1,178d' ${DOWNLOADED_DISTFILE} |		\
		${GTAR} xzf - -C ${WRKSRC}

pre-extract:
	${MKDIR} ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${RTCWDIR}
	cd ${WRKSRC} && pax -rw -p am . ${DESTDIR}${RTCWDIR}

.include "../../mk/bsd.pkg.mk"
