# $NetBSD: Makefile,v 1.2 2001/11/28 14:33:09 jlam Exp $
#

DISTNAME=		netmaj-2.0.7
WRKSRC=			${WRKDIR}/netmaj
CATEGORIES=		games
MASTER_SITES=		http://www.sfc.wide.ad.jp/~kusune/netmaj/files/

MAINTAINER=		kei@netbsd.org
HOMEPAGE=		http://www.sfc.wide.ad.jp/~kusune/netmaj/
COMMENT=		mahjongg game with network and 1-4 player(s) support

USE_BUILDLINK_ONLY=	YES
WRKSRC=			${WRKDIR}/netmaj

INSTALL_TARGET=		install install-pf
HTMLDIR=		${PREFIX}/share/doc/html/netmaj

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} libs
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/html/* ${HTMLDIR}

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
