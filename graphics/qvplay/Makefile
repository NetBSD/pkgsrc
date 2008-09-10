# $NetBSD: Makefile,v 1.12 2008/09/10 14:01:58 gdt Exp $
#

DISTNAME=	qvplay-0.94
CATEGORIES=	graphics
MASTER_SITES=	http://www.asahi-net.or.jp/~xg2k-hys/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.asahi-net.or.jp/~xg2k-hys/index-e.html
COMMENT=	Software for use with CASIO QV digital cameras

LICENSE=	generic-nonlicense
RESTRICTED=	No permission to distribute
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/QVplay094/src
GNU_CONFIGURE=	yes
CONFIGURE_HAS_MANDIR=	NO

.include "../../mk/bsd.pkg.mk"
