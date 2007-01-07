# $NetBSD: Makefile,v 1.12 2007/01/07 13:14:15 rillig Exp $
#

DISTNAME=	fortunes-de-0.20
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/f/fortunes-de/}
DISTFILES=	fortunes-de_0.20.orig.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packages.debian.org/unstable/games/fortunes-de.html
COMMENT=	German data files for fortune

BUILD_DEPENDS+=	fortune-strfile-[0-9]*:../../games/fortune-strfile

STRFILE=	${LOCALBASE}/bin/strfile
INSTALLATION_DIRS=	share/games/fortune/de
CHECK_PORTABILITY_SKIP=	install.sh

do-build:
	find ${WRKSRC}/data -type f -exec ${STRFILE} {} \;

do-install:
	cd ${WRKSRC}/data && pax -rw . ${PREFIX}/share/games/fortune/de

.include "../../mk/bsd.pkg.mk"
