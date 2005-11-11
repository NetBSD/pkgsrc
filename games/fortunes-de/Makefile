# $NetBSD: Makefile,v 1.9 2005/11/11 20:26:57 wiz Exp $
#

DISTNAME=	fortunes-de_0.19.orig
PKGNAME=	fortunes-de-0.19
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/f/fortunes-de/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://packages.debian.org/unstable/games/fortunes-de.html
COMMENT=	German data files for fortune

BUILD_DEPENDS+=	fortune-strfile-[0-9]*:../../games/fortune-strfile
STRFILE=	${LOCALBASE}/bin/strfile

WRKSRC=		${WRKDIR}/fortunes-de-0.19

do-build:
	${FIND} ${WRKSRC}/data -type f -exec ${STRFILE} {} \;

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/games/fortune/de
	cd ${WRKSRC}/data && ${PAX} -rw . ${PREFIX}/share/games/fortune/de

.include "../../mk/bsd.pkg.mk"
