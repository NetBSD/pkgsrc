# $NetBSD: Makefile,v 1.2 2000/01/20 15:24:37 hubertf Exp $
#

DISTNAME=	jwhois-2.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coyote.org/pub/jwhois/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.coyote.org/jwhois/

USE_GTEXINFO=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=/etc

post-install:
	${INSTALL_DATA} ${WRKSRC}/example/jwhois.conf ${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
