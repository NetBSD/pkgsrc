# $NetBSD: Makefile,v 1.10 2007/03/21 18:55:48 jwise Exp $
#

DISTNAME=	qvplay-0.94
CATEGORIES=	graphics
MASTER_SITES=	http://www.asahi-net.or.jp/~xg2k-hys/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.asahi-net.or.jp/~xg2k-hys/index-e.html
COMMENT=	Software for use with CASIO QV digital cameras

RESTRICTED=	Undistributable development version.
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/QVplay094/src
GNU_CONFIGURE=	yes
CONFIGURE_HAS_MANDIR=	NO

.include "../../mk/bsd.pkg.mk"
