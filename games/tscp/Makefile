# $NetBSD: Makefile,v 1.9 2004/04/01 14:38:32 abs Exp $
#

DISTNAME=	tscp181
PKGNAME=	tscp-1.81
CATEGORIES=	games benchmarks
MASTER_SITES=	http://home.comcast.net/~tckerrigan/
EXTRACT_SUFX=	.zip

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://home.comcast.net/~tckerrigan/
COMMENT=	Tom Kerrigan's Simple Chess Program

RESTRICTED= No distribtion without authorisation from Tom Kerrigan

NO_BIN_ON_CDROM= ${RESTRICTED}
NO_SRC_ON_CDROM= ${RESTRICTED}
NO_BIN_ON_FTP= ${RESTRICTED}
NO_SRC_ON_FTP= ${RESTRICTED}

do-build:
	cd ${WRKSRC} ; ${CC} ${CFLAGS} ${LDFLAGS} -o tscp *.c -lcompat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tscp ${PREFIX}/bin/tscp
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/tscp.txt

.include "../../mk/bsd.pkg.mk"
