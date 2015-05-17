# $NetBSD: Makefile,v 1.2 2015/05/17 10:53:07 mef Exp $

DISTNAME=	rmtrash-1.8
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=PhrozenByte/}
GITHUB_TAG=	v1.8

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PhrozenByte/rmtrash/
COMMENT=	Put files into OS X' trash when deleting them
LICENSE=	gnu-gpl-v3
#' (to pair above single quote for some editors)
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
