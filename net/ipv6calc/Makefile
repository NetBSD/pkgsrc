# $NetBSD: Makefile,v 1.28 2005/05/22 20:08:24 jlam Exp $
#

DISTNAME=	ipv6calc-0.48
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bieringer.de/pub/linux/IPv6/ipv6calc/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.bieringer.de/linux/IPv6/ipv6calc/
COMMENT=	Manipulates IPv6 addresses

# This package does not set or evaluate USE_INET6, but it should still
# be listed in README-IPv6.html. Leave this comment here to make it so!

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

MAKE_ENV+=	root=${PREFIX}
INSTALL_TARGET=	installonly

.include "../../mk/bsd.pkg.mk"
