# $NetBSD: Makefile,v 1.1.1.1 1999/10/05 14:17:15 kim Exp $
#

DISTNAME=	jwhois-2.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coyote.org/pub/jwhois/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.coyote.org/jwhois/

USE_GTEXINFO=	yes

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=/etc

post-install:
	${INSTALL_DATA} ${WRKSRC}/example/jwhois.conf ${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
