# $NetBSD: Makefile,v 1.11 2002/11/04 23:08:22 hubertf Exp $
#

DISTNAME=	ipv6calc-0.44
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bieringer.de/pub/linux/IPv6/ipv6calc/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.bieringer.de/linux/IPv6/ipv6calc/index.html
COMMENT=	Manipulates IPv6 adresses


# This package does not set or evaluate USE_INET6, but it should still
# be listed in README-IPv6.html. Leave this comment here to make it so!

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ENV+=	root=${PREFIX}
INSTALL_TARGET=	installonly

.include "../../mk/bsd.pkg.mk"
