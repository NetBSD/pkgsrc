# $NetBSD: Makefile,v 1.1.1.1 2010/03/09 22:05:53 snj Exp $

DISTNAME=	quake3-latest-pk3s
PKGNAME=	ioquake3-pk3-0
CATEGORIES=	games
#The link is obtained from http://ioquake3.org/patch-data/
MASTER_SITES=	http://offload1.icculus.org/~zakk/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ioquake3.org/
COMMENT=	pk3 files for ioquake3
LICENSE=	quake3arena-license

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	lib/ioquake3/baseq3 lib/ioquake3/missionpack

USE_LANGUAGES=	# none
NO_BUILD=	yes

RESTRICTED=		Use is restricted by id Software.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

do-install:
	${INSTALL_DATA} ${WRKSRC}/baseq3/* \
		${DESTDIR}${PREFIX}/lib/ioquake3/baseq3/
	${INSTALL_DATA} ${WRKSRC}/missionpack/* \
		${DESTDIR}${PREFIX}/lib/ioquake3/missionpack/

.include "../../mk/bsd.pkg.mk"
