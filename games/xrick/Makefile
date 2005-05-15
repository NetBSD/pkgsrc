# $NetBSD: Makefile,v 1.12 2005/05/15 22:02:27 jlam Exp $
#

DISTNAME=	xrick-021212
PKGREVISION=	6
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

USE_GNU_TOOLS+=		make
PKGSRC_USE_TOOLS+=	gunzip
USE_X11=		YES

SUBST_CLASSES+=		data
SUBST_STAGE.data=	post-patch
SUBST_MESSAGE.data=	Adjusting path to data.zip
SUBST_FILES.data=	src/xrick.c
SUBST_SED.data=		-e "s|data.zip|${PREFIX}/share/xrick/&|"

post-extract:
	cd ${WRKSRC} && ${GUNZIP_CMD} xrick.6.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrick ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xrick.6 ${PREFIX}/man/man6
	${INSTALL_DATA_DIR} ${PREFIX}/share/xrick
	${INSTALL_DATA} ${WRKSRC}/data.zip ${PREFIX}/share/xrick

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
