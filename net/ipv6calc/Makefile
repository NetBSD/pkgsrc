# $NetBSD: Makefile,v 1.33 2007/09/07 22:12:17 jlam Exp $
#

DISTNAME=	ipv6calc-0.61.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bieringer.de/pub/linux/IPv6/ipv6calc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.deepspace6.net/projects/ipv6calc.html
COMMENT=	Manipulates IPv6 addresses

# This package does not set or evaluate IPV6_READY, but it should still
# be listed in README-IPv6.html. Leave this comment here to make it so!
#
BUILD_DEFS+=	IPV6_READY

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

INSTALL_TARGET=	installonly

.include "../../mk/bsd.pkg.mk"
