# $NetBSD: Makefile,v 1.2 2001/01/31 10:07:02 abs Exp $
#

DISTNAME=	tscp171
PKGNAME=	tscp-1.71nb1
CATEGORIES=	games benchmarks
MASTER_SITES=	http://ucsu.colorado.edu/~kerrigat/
EXTRACT_SUFX=	.zip

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://ucsu.colorado.edu/~kerrigat/

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
