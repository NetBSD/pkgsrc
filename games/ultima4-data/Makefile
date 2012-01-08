# $NetBSD: Makefile,v 1.1.1.1 2012/01/08 15:52:52 wiz Exp $
#

DISTNAME=	UltimaIV
PKGNAME=	ultima4-data-1.0
CATEGORIES=	games
MASTER_SITES=	#
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ultimaforever.com/
COMMENT=	Ultima IV data files for xu4
#LICENSE=	http://www.ultimaforever.com/PCDownload_EULA.html
#LICENSE+=	http://tos.ea.com/legalapp/WEBPRIVACY/US/en/PC/
#LICENSE+=	http://tos.ea.com/legalapp/WEBTERMS/US/en/PC/

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	lib/u4/ultima4 share/doc/ultima4
WRKSRC=			${WRKDIR}/ultima4

RESTRICTED=	Redistribution not permitted
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
FETCH_MESSAGE+=	"The file ${DISTNAME}${EXTRACT_SUFX} must be downloaded manually from:"
FETCH_MESSAGE+=	"	${HOMEPAGE}"
FETCH_MESSAGE+=	"and saved to:"
FETCH_MESSAGE+=	"	${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}"

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.* ${DESTDIR}${PREFIX}/lib/u4/ultima4
	${INSTALL_DATA} ${WRKSRC}/EXTRAS/*.* ${DESTDIR}${PREFIX}/share/doc/ultima4

.include "../../mk/bsd.pkg.mk"
