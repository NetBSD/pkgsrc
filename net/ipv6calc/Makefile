# $NetBSD: Makefile,v 1.7 2002/02/24 04:33:02 hubertf Exp $
#

DISTNAME=	ipv6calc-0.36
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bieringer.de/pub/linux/IPv6/ipv6calc/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.bieringer.de/linux/IPv6/tools/index.html#ipv6calc
COMMENT=	Manipulates IPv6 adresses

USE_GMAKE=	yes
ALL_TARGET=	ipv6calc

# This package does not set or evaluate USE_INET6, but it should still
# be listed in README-IPv6.html. Leave this comment here to make it so!

MAKE_ENV+=	CC="${CC} -D_NETINET_IN_H"

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/ipv6calc ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
