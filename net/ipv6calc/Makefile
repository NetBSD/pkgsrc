# $NetBSD: Makefile,v 1.24 2004/10/03 00:17:53 tv Exp $
#

DISTNAME=	ipv6calc-0.46
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bieringer.de/pub/linux/IPv6/ipv6calc/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.bieringer.de/linux/IPv6/ipv6calc/
COMMENT=	Manipulates IPv6 addresses

# This package does not set or evaluate USE_INET6, but it should still
# be listed in README-IPv6.html. Leave this comment here to make it so!

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make

MAKE_ENV+=	root=${PREFIX}
INSTALL_TARGET=	installonly

.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
