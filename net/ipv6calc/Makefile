# $NetBSD: Makefile,v 1.19 2003/11/12 03:39:41 jschauma Exp $
#

DISTNAME=	ipv6calc-0.46
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bieringer.de/pub/linux/IPv6/ipv6calc/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.bieringer.de/linux/IPv6/ipv6calc/
COMMENT=	Manipulates IPv6 adresses

# This package does not set or evaluate USE_INET6, but it should still
# be listed in README-IPv6.html. Leave this comment here to make it so!

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES

MAKE_ENV+=	root=${PREFIX}
INSTALL_TARGET=	installonly

.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
