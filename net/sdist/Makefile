# $NetBSD: Makefile,v 1.7 2001/03/29 22:22:53 kim Exp $
#

DISTNAME=		sdist-1.6
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		invoke rdist to distribute files to a set of hosts

DEPENDS+=		netname-*:../../net/netname
DEPENDS+=		osname-*:../../sysutils/osname
DEPENDS+=		freerdist-*:../../net/rdist6
DEPENDS+=		srsh-*:../../net/srsh

.include "../../mk/bsd.prefs.mk"

SDIST_PAWD?=		pwd

NO_CONFIGURE=		yes
ALL_TARGET=		all PREFIX=${PREFIX} PAWD=${SDIST_PAWD}
INSTALL_TARGET=		install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
