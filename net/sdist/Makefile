# $NetBSD: Makefile,v 1.1.1.1 1999/08/30 17:47:17 kim Exp $
#

DISTNAME=		sdist-1.1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us

DEPENDS+=		osname-*:../../sysutils/osname
DEPENDS+=		rdist-6.1.4:../../net/rdist6
DEPENDS+=		srsh-*:../../net/srsh

NO_CONFIGURE=		yes
ALL_TARGET=		all PREFIX=${PREFIX}
INSTALL_TARGET=		install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
