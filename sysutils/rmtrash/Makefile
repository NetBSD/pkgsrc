# $NetBSD: Makefile,v 1.3 2015/05/17 12:12:49 mef Exp $

DISTNAME=	rmtrash-1.11
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=PhrozenByte/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

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
