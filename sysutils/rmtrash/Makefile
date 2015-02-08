# $NetBSD: Makefile,v 1.1 2015/02/08 16:59:56 wiz Exp $

DISTNAME=	rmtrash-${VERSION}
VERSION=	1.8
CATEGORIES=	sysutils
MASTER_SITES=	-https://github.com/PhrozenByte/rmtrash/archive/v${VERSION}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PhrozenByte/rmtrash/
COMMENT=	Put files into OS X' trash when deleting them
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		# none
USE_TOOLS+=		bash:run
REPLACE_BASH+=		rmdirtrash rmtrash
INSTALLATION_DIRS+=	bin share/doc/rmtrash

do-build:
	# nothing

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rmdirtrash ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/rmtrash ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/rmtrash

.include "../../mk/bsd.pkg.mk"
