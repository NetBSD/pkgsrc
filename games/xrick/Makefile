# $NetBSD: Makefile,v 1.2 2002/08/27 19:09:12 jlam Exp $
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
USE_BUILDLINK2=		YES
USE_X11=		YES
HAS_CONFIGURE=		YES

CONFIGURE_SCRIPT=	./config

post-extract:
	cd ${WRKSRC} && ${GUNZIP_CMD} xrick.6.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrick ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xrick.6 ${PREFIX}/man/man6

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
