# $NetBSD: Makefile,v 1.19 2008/09/12 22:46:52 gdt Exp $
#

DISTNAME=	xfrisk-1.2
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.tuxick.net/xfrisk/files/

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://www.tuxick.net/xfrisk/
COMMENT=	X11 version of the classic Risk board game

WRKSRC=		${WRKDIR}/XFrisk
USE_TOOLS+=	gmake

# LICENSE pending investigation; absence of LICENSE violates
# "RESTRICTED implies LICENSE" pkgsrc rule.
#LICENSE=	gnu-gpl-v2
LICENSE+=	generic-nonlicense
RESTRICTED=	Possible trademark infringement
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

.include "../../mk/bsd.prefs.mk"

LIBS.SunOS=	-lsocket -lnsl
MAKE_ENV+=	LIBS=${LIBS:Q}

# xfrisk doesn't work with standard Xaw.
XAW_TYPE?=	3d

.if ${XAW_TYPE} == standard
XAW_TYPE=3d
.endif

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
