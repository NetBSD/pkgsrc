# $NetBSD: Makefile,v 1.1.1.1 2002/10/01 10:33:17 drochner Exp $
#

DISTNAME=	fortunes-de_0.6.orig
PKGNAME=	fortunes-de-0.6
CATEGORIES=	games
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/f/fortunes-de/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://packages.debian.org/unstable/games/fortunes-de.html
COMMENT=	German data files for fortune

WRKSRC=		${WRKDIR}/fortunes-de-0.6

BUILD_DEPENDS+=	fortune-strfile-*:../../games/fortune-strfile
STRFILE=	${LOCALBASE}/bin/strfile

do-build:
	${FIND} ${WRKSRC}/data -type f -exec ${STRFILE} {} \;

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/games/fortune/de
	(cd ${WRKSRC}/data; ${PAX} -rw . ${PREFIX}/share/games/fortune/de)

.include "../../mk/bsd.pkg.mk"
