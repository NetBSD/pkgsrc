# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 18:46:12 jlam Exp $
#

DISTNAME=	xrick-010808
WRKSRC=		${WRKDIR}/xrick
CATEGORIES=	games
MASTER_SITES=	http://www.bigorno.net/xrick/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pino@dohd.org
HOMEPAGE=	http://www.bigorno.net/xrick/
COMMENT=	Rick Dangerous clone for X

RESTRICTED=     "Copyright of graphics, images, maps, and sounds is questionable."
NO_BIN_ON_CDROM=    ${RESTRICTED}
NO_SRC_ON_CDROM=    ${RESTRICTED}
NO_BIN_ON_FTP=	    ${RESTRICTED}
NO_SRC_ON_FTP=	    ${RESTRICTED}

USE_GMAKE=		YES
USE_BUILDLINK_ONLY=	YES
HAS_CONFIGURE=		YES

CONFIGURE_SCRIPT=	./config

post-extract:
	cd ${WRKSRC} && ${GUNZIP_CMD} xrick.6.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrick ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xrick.6 ${PREFIX}/man/man6

.include "../../devel/SDL/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
