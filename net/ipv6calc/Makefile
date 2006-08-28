# $NetBSD: Makefile,v 1.32 2006/08/28 22:02:51 hubertf Exp $
#

DISTNAME=	ipv6calc-0.61.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bieringer.de/pub/linux/IPv6/ipv6calc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.deepspace6.net/projects/ipv6calc.html
COMMENT=	Manipulates IPv6 addresses

# This package does not set or evaluate USE_INET6, but it should still
# be listed in README-IPv6.html. Leave this comment here to make it so!

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

INSTALL_TARGET=	installonly

.include "../../mk/bsd.pkg.mk"
