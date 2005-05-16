# $NetBSD: Makefile,v 1.6 2005/05/16 01:15:32 jlam Exp $

DISTNAME=	wolf-linux-1.33.x86
PKGNAME=	rtcw-1.33
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/wolf/linux/
EXTRACT_SUFX=	.run

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://games.activision.com/games/wolfenstein/
COMMENT=	Return to Castle Wolfenstein for Linux

ONLY_FOR_PLATFORM=	*-*-i386
NOT_FOR_PLATFORM=	NetBSD-*-*

CHECK_SHLIBS=		no
NO_BUILD=		yes
RTCWDIR=		${PREFIX}/lib/lokigames/rtcw
RESTRICTED=		"Size; the data set is much too big"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
EXTRACT_CMD=	${SED} '1,178d' ${DOWNLOADED_DISTFILE} | ${GTAR} xzf - \
		    -C ${WRKSRC}
PKGSRC_USE_TOOLS+=	gtar

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
DEPENDS+=       suse_base>=6.3:../../emulators/${SUSE_DIR_PREFIX}_base
.include "../../emulators/suse_linux/Makefile.application"
.else
USE_X11=	yes
.endif

pre-extract:
	${MKDIR} ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${RTCWDIR}
	cd ${WRKSRC} && ${PAX} -rw -p am . ${RTCWDIR}

.include "../../mk/bsd.pkg.mk"
