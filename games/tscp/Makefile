# $NetBSD: Makefile,v 1.6 2001/12/20 01:34:41 simonb Exp $
#

DISTNAME=	tscp173
PKGNAME=	tscp-1.73
CATEGORIES=	games benchmarks
MASTER_SITES=	http://home.earthlink.net/~tckjr/
EXTRACT_SUFX=	.zip

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://home.earthlink.net/~tckjr/
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
