# $NetBSD: Makefile,v 1.22 2026/02/14 08:37:17 wiz Exp $

DISTNAME=	tscp181
PKGNAME=	tscp-1.81
PKGREVISION=	3
CATEGORIES=	games benchmarks
MASTER_SITES=	https://www.tckerrigan.com/Chess/TSCP/
EXTRACT_SUFX=	.zip

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://www.tckerrigan.com/Chess/TSCP/
COMMENT=	Tom Kerrigan's Simple Chess Program
LICENSE=	generic-nonlicense

RESTRICTED=		No distribution without authorisation from Tom Kerrigan
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

INSTALLATION_DIRS=	bin share/doc

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -o tscp *.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tscp ${DESTDIR}${PREFIX}/bin/tscp
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DESTDIR}${PREFIX}/share/doc/tscp.txt

.include "../../mk/bsd.pkg.mk"
