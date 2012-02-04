# $NetBSD: Makefile,v 1.26 2012/02/04 23:42:12 dholland Exp $
#

DISTNAME=	xfrisk-1.2
PKGREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www.tuxick.net/xfrisk/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tuxick.net/xfrisk/
COMMENT=	X11 version of the classic Risk board game
# LICENSE pending investigation; absence of LICENSE violates
# "RESTRICTED implies LICENSE" pkgsrc rule.
#LICENSE=	gnu-gpl-v2
LICENSE+=	generic-nonlicense

PKG_DESTDIR_SUPPORT=	user-destdir

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
XAW_TYPE?=	3d

.if ${XAW_TYPE} == standard
XAW_TYPE=3d
.endif

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
