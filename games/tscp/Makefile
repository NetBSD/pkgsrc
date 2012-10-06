# $NetBSD: Makefile,v 1.19 2012/10/06 11:54:57 asau Exp $
#

DISTNAME=	tscp181
PKGNAME=	tscp-1.81
PKGREVISION=	3
CATEGORIES=	games benchmarks
MASTER_SITES=	http://www.tckerrigan.com/Chess/TSCP/attachments/
EXTRACT_SUFX=	.zip

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.tckerrigan.com/
COMMENT=	Tom Kerrigan's Simple Chess Program
LICENSE=	generic-nonlicense

RESTRICTED=	No distribution without authorisation from Tom Kerrigan
NO_BIN_ON_CDROM= ${RESTRICTED}
NO_BIN_ON_FTP= ${RESTRICTED}
NO_SRC_ON_CDROM= ${RESTRICTED}
NO_SRC_ON_FTP= ${RESTRICTED}

INSTALLATION_DIRS=	bin share/doc

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -o tscp *.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tscp ${DESTDIR}${PREFIX}/bin/tscp
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DESTDIR}${PREFIX}/share/doc/tscp.txt

.include "../../mk/bsd.pkg.mk"
