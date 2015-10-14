# $NetBSD: Makefile,v 1.32 2015/10/14 20:17:25 wiz Exp $

DISTNAME=	xfrisk-1.2
PKGREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://www.tuxick.net/xfrisk/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tuxick.net/xfrisk/
COMMENT=	X11 version of the classic Risk board game
# LICENSE pending investigation; absence of LICENSE violates
# "RESTRICTED implies LICENSE" pkgsrc rule.
#LICENSE=	gnu-gpl-v2
LICENSE=	generic-nonlicense

WRKSRC=		${WRKDIR}/XFrisk
USE_TOOLS+=	gmake

RESTRICTED=	Possible trademark infringement
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

.include "../../mk/bsd.prefs.mk"

LIBS.SunOS=	-lsocket -lnsl
MAKE_ENV+=	LIBS=${LIBS:Q}

# xfrisk doesn't work with standard Xaw.
XAW_TYPE=	3d
# does not directly support Xaw3d
BUILDLINK_TRANSFORM+=   l:Xaw:Xaw3d
.PHONY: buildlink-Xaw3d-inc-hack
pre-configure: buildlink-Xaw3d-inc-hack

buildlink-Xaw3d-inc-hack: buildlink-directories
	cd ${BUILDLINK_DIR}/include/X11 && ln -s Xaw3d Xaw

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
