# $NetBSD: Makefile,v 1.22 2026/01/06 08:41:20 wiz Exp $

DISTNAME=		TS-1.08
PKGNAME=		libts-1.08
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		https://www.aydogan.net/distfiles/devel/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		https://www.aydogan.net/distfiles/devel/
COMMENT=		Library of simple token-scanning routines

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/tokenscan
INSTALLATION_DIRS=	include lib
USE_TOOLS+=		nroff

INSTALLATION_DIRS=	include lib share/doc/libts

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} <${WRKSRC}/Makefile.bak >${WRKSRC}/Makefile \
		-e "s|/usr/local|${PREFIX}|"

do-install:
	${INSTALL_DATA} ${WRKSRC}/libtokenscan.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/tokenscan.h ${DESTDIR}${PREFIX}/include
	nroff -ms ${WRKSRC}/tokenscan.ms \
		>${DESTDIR}${PREFIX}/share/doc/libts/tokenscan.txt

.include "../../mk/bsd.pkg.mk"
