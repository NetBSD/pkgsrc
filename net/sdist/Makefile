# $NetBSD: Makefile,v 1.5 2000/11/20 23:42:54 kim Exp $
#

DISTNAME=		sdist-1.5
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us

DEPENDS+=		netname-*:../../net/netname
DEPENDS+=		osname-*:../../sysutils/osname
DEPENDS+=		freerdist-*:../../net/rdist6
DEPENDS+=		srsh-*:../../net/srsh

NO_CONFIGURE=		yes
ALL_TARGET=		all PREFIX=${PREFIX}
INSTALL_TARGET=		install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
