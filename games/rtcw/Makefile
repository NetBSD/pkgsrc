# $NetBSD: Makefile,v 1.12 2006/05/22 22:22:03 jlam Exp $

DISTNAME=	wolf-linux-1.33.x86
PKGNAME=	rtcw-1.33
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/wolf/linux/
EXTRACT_SUFX=	.run

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://games.activision.com/games/wolfenstein/
COMMENT=	Return to Castle Wolfenstein for Linux

ONLY_FOR_PLATFORM=	*-*-i386
NOT_FOR_PLATFORM=	NetBSD-*-*

NO_BUILD=		yes
RTCWDIR=		${PREFIX}/lib/lokigames/rtcw
RESTRICTED=		Size; the data set is much too big
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
EXTRACT_CMD=	${SED} '1,178d' ${DOWNLOADED_DISTFILE} | ${GTAR} xzf - \
		    -C ${WRKSRC}
USE_TOOLS+=	gtar

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
DEPENDS+=       suse_base>=6.3:../../emulators/${SUSE_DIR_PREFIX}_base
.include "../../emulators/suse_linux/Makefile.application"
.else
.include "../../mk/x11.buildlink3.mk"
.endif

pre-extract:
	${MKDIR} ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${RTCWDIR}
	cd ${WRKSRC} && ${PAX} -rw -p am . ${RTCWDIR}

.include "../../mk/bsd.pkg.mk"
