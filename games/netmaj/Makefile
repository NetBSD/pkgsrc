# $NetBSD: Makefile,v 1.1.1.1 2001/04/22 09:58:59 kei Exp $
#

DISTNAME=		netmaj-2.0.7
WRKSRC=			${WRKDIR}/netmaj
CATEGORIES=		games
MASTER_SITES=		http://www.sfc.wide.ad.jp/~kusune/netmaj/files/

MAINTAINER=		kei@netbsd.org
HOMEPAGE=		http://www.sfc.wide.ad.jp/~kusune/netmaj/
COMMENT=		mahjongg game with network and 1-4 player(s) support

USE_PERL5=		YES
WRKSRC=			${WRKDIR}/netmaj

do-build:
			cd ${WRKSRC}; \
			${MAKE} libs; ${MAKE};

do-install:
			cd ${WRKSRC}; \
			${MAKE} install install-pf; \
			${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/netmaj; \
			${INSTALL_DATA} html/* ${PREFIX}/share/doc/html/netmaj

.include "../../mk/bsd.pkg.mk"
