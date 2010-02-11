# $NetBSD: Makefile,v 1.35 2010/02/11 21:38:06 joerg Exp $
#

DISTNAME=	ipv6calc-0.72.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bieringer.de/pub/linux/IPv6/ipv6calc/ \
		ftp://sunsite.icm.edu.pl/pub/Linux/ipv6/bipv6/ipv6calc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.deepspace6.net/projects/ipv6calc.html
COMMENT=	Manipulates IPv6 addresses

PKG_DESTDIR_SUPPORT=	user-destdir

# This package does not set or evaluate IPV6_READY, but it should still
# be listed in README-IPv6.html. Leave this comment here to make it so!
#
BUILD_DEFS+=	IPV6_READY

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

INSTALL_TARGET=	install

.include "../../mk/bsd.pkg.mk"
