# $NetBSD: Makefile,v 1.18 2020/01/26 17:31:23 rillig Exp $
#

DISTNAME=	qvplay-0.95
CATEGORIES=	graphics
MASTER_SITES=	http://www.asahi-net.or.jp/~xg2k-hys/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.asahi-net.or.jp/~xg2k-hys/index-e.html
COMMENT=	Software for use with CASIO QV digital cameras
LICENSE=	generic-nonlicense

RESTRICTED=		No permission to distribute
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=			${WRKDIR}/QVplay095/src
GNU_CONFIGURE=		yes
CONFIGURE_HAS_MANDIR=	NO

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
