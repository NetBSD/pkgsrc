# $NetBSD: Makefile,v 1.15 2003/02/06 15:31:48 tron Exp $

DISTNAME=	ipv6calc-0.45
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bieringer.de/pub/linux/IPv6/ipv6calc/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.bieringer.de/linux/IPv6/ipv6calc/
COMMENT=	Manipulates IPv6 adresses

# This package does not set or evaluate USE_INET6, but it should still
# be listed in README-IPv6.html. Leave this comment here to make it so!

GNU_CONFIGURE=	yes
USE_BUILDLINK=	yes
USE_GMAKE=	yes
MAKE_ENV+=	root=${PREFIX}
INSTALL_TARGET=	installonly

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
