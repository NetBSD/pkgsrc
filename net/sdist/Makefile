# $NetBSD: Makefile,v 1.6 2001/02/17 18:19:35 wiz Exp $
#

DISTNAME=		sdist-1.5
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		invoke rdist to distribute files to a set of hosts

DEPENDS+=		netname-*:../../net/netname
DEPENDS+=		osname-*:../../sysutils/osname
DEPENDS+=		freerdist-*:../../net/rdist6
DEPENDS+=		srsh-*:../../net/srsh

NO_CONFIGURE=		yes
ALL_TARGET=		all PREFIX=${PREFIX}
INSTALL_TARGET=		install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
