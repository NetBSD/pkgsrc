# $NetBSD: Makefile,v 1.29 2005/11/08 21:50:15 hubertf Exp $
#

DISTNAME=	ipv6calc-0.50
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bieringer.de/pub/linux/IPv6/ipv6calc/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.deepspace6.net/projects/ipv6calc.html
COMMENT=	Manipulates IPv6 addresses

# This package does not set or evaluate USE_INET6, but it should still
# be listed in README-IPv6.html. Leave this comment here to make it so!

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

INSTALL_TARGET=	installonly

.include "../../mk/bsd.pkg.mk"
