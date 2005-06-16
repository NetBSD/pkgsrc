# $NetBSD: Makefile,v 1.15 2005/06/16 06:57:56 jlam Exp $
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

USE_TOOLS+=		gmake
PKGSRC_USE_TOOLS+=	gunzip

SUBST_CLASSES+=		data
SUBST_STAGE.data=	post-patch
SUBST_MESSAGE.data=	Adjusting path to data.zip
SUBST_FILES.data=	src/xrick.c
SUBST_SED.data=		-e "s|data.zip|${PREFIX}/share/xrick/&|"

INSTALLATION_DIRS=	bin man/man6

post-extract:
	cd ${WRKSRC} && ${GUNZIP_CMD} xrick.6.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrick ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xrick.6 ${PREFIX}/man/man6
	${INSTALL_DATA_DIR} ${PREFIX}/share/xrick
	${INSTALL_DATA} ${WRKSRC}/data.zip ${PREFIX}/share/xrick

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
