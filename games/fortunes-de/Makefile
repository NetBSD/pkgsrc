# $NetBSD: Makefile,v 1.4 2003/06/02 01:19:41 jschauma Exp $
#

DISTNAME=	fortunes-de_0.6.orig
PKGNAME=	fortunes-de-0.6
WRKSRC=		${WRKDIR}/fortunes-de-0.6
CATEGORIES=	games
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/f/fortunes-de/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://packages.debian.org/unstable/games/fortunes-de.html
COMMENT=	German data files for fortune

BUILD_DEPENDS+=	fortune-strfile-*:../../games/fortune-strfile
STRFILE=	${LOCALBASE}/bin/strfile

do-build:
	${FIND} ${WRKSRC}/data -type f -exec ${STRFILE} {} \;

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/games/fortune/de
	cd ${WRKSRC}/data && ${PAX} -rw . ${PREFIX}/share/games/fortune/de

.include "../../mk/bsd.pkg.mk"
