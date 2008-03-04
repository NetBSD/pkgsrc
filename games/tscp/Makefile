# $NetBSD: Makefile,v 1.15 2008/03/04 06:59:06 jlam Exp $
#

DISTNAME=	tscp181
PKGNAME=	tscp-1.81
PKGREVISION=	1
CATEGORIES=	games benchmarks
MASTER_SITES=	http://home.comcast.net/~tckerrigan/
EXTRACT_SUFX=	.zip

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://home.comcast.net/~tckerrigan/
COMMENT=	Tom Kerrigan's Simple Chess Program

RESTRICTED=	No distribution without authorisation from Tom Kerrigan

NO_BIN_ON_CDROM= ${RESTRICTED}
NO_SRC_ON_CDROM= ${RESTRICTED}
NO_BIN_ON_FTP= ${RESTRICTED}
NO_SRC_ON_FTP= ${RESTRICTED}

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} ; ${CC} ${CFLAGS} ${LDFLAGS} -o tscp *.c -lcompat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tscp ${DESTDIR}${PREFIX}/bin/tscp
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DESTDIR}${PREFIX}/share/doc/tscp.txt

.include "../../mk/bsd.pkg.mk"
