# $NetBSD: Makefile,v 1.8 2001/09/27 23:18:31 jlam Exp $
#

DISTNAME=		sdist-1.6
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		invoke rdist to distribute files to a set of hosts

DEPENDS+=		netname-[0-9]*:../../net/netname
DEPENDS+=		osname-[0-9]*:../../sysutils/osname
DEPENDS+=		freerdist-[0-9]*:../../net/rdist6
DEPENDS+=		srsh-[0-9]*:../../net/srsh

.include "../../mk/bsd.prefs.mk"

SDIST_PAWD?=		pwd

NO_CONFIGURE=		yes
ALL_TARGET=		all PREFIX=${PREFIX} PAWD=${SDIST_PAWD}
INSTALL_TARGET=		install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
