# $NetBSD: Makefile,v 1.17 2020/01/26 17:31:15 rillig Exp $
#

DISTNAME=	fortunes-de-0.20
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/f/fortunes-de/}
DISTFILES=	fortunes-de_0.20.orig.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://packages.debian.org/unstable/games/fortunes-de.html
COMMENT=	German data files for fortune

BUILD_DEPENDS+=	fortune-strfile-[0-9]*:../../games/fortune-strfile

STRFILE=		${LOCALBASE}/bin/strfile
INSTALLATION_DIRS=	share/games/fortune/de
CHECK_PORTABILITY_SKIP=	install.sh

USE_TOOLS+=		pax

do-build:
	find ${WRKSRC}/data -type f ! -name "*.dat" -exec ${STRFILE} {} \;

do-install:
	cd ${WRKSRC}/data && pax -rw . \
		${DESTDIR}${PREFIX}/share/games/fortune/de

.include "../../mk/bsd.pkg.mk"
