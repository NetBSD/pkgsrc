# $NetBSD: Makefile,v 1.2 2006/08/14 13:31:21 rpaulo Exp $

DISTNAME=	thrulay-0.8
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.internet2.edu/~shalunov/thrulay/

MAINTAINER=	rpaulo@NetBSD.org
HOMEPAGE=	http://www.internet2.edu/~shalunov/thrulay/
COMMENT=	TCP and UDP network capacity tester

ONLY_FOR_PLATFORM=	DragonFly-*-i386 FreeBSD-*-i386 Linux-*-i386 \
			NetBSD-*-i386

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	bin share/doc/thrulay

.include "../../mk/bsd.pkg.mk"
