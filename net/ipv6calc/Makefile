# $NetBSD: Makefile,v 1.37 2013/10/21 09:22:43 fhajny Exp $
#

DISTNAME=	ipv6calc-0.94.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bieringer.de/pub/linux/IPv6/ipv6calc/ \
		ftp://sunsite.icm.edu.pl/pub/Linux/ipv6/bipv6/ipv6calc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.deepspace6.net/projects/ipv6calc.html
COMMENT=	Manipulates IPv6 addresses
LICENSE=	gnu-gpl-v2

# This package does not set or evaluate IPV6_READY, but it should still
# be listed in README-IPv6.html. Leave this comment here to make it so!
#
BUILD_DEFS+=	IPV6_READY

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

INSTALL_TARGET=	install

.include "../../mk/bsd.pkg.mk"
