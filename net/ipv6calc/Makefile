# $NetBSD: Makefile,v 1.1.1.1 2001/03/04 15:59:22 hubertf Exp $
#

DISTNAME=	ipv6calc-0.10
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bieringer.de/pub/linux/IPv6/ipv6calc/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.bieringer.de/linux/IPv6/tools/index.html#ipv6calc
COMMENT=	Manipulates IPv6 adresses

USE_GMAKE=	yes
ALL_TARGET=	ipv6calc

MAKE_ENV+=	CC="${CC} -D_NETINET_IN_H"

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/ipv6calc ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
