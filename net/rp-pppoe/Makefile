# $NetBSD: Makefile,v 1.2 2000/07/11 21:37:24 tron Exp $

DISTNAME=	rp-pppoe-1.9
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}src/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://home.sprynet.com/~minaret/pppoe/

DEPENDS+=	ppp>=2.3.10:../ppp

CONFLICTS+=	mouse_pppoe-*

GNU_CONFIGURE=	yes

ALL_TARGET=	pppoe

post-install:
	${INSTALL_DATA} ${WRKSRC}/pppoe.conf ${PREFIX}/share/doc/rp-pppoe

.include "../../mk/bsd.pkg.mk"
