# $NetBSD: Makefile,v 1.5 2001/03/29 22:22:53 kim Exp $
#

DISTNAME=		ssync-1.6
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		invoke rsync to distribute files to a set of hosts

DEPENDS+=		netname-*:../../net/netname
DEPENDS+=		osname-*:../../sysutils/osname
DEPENDS+=		rsync>=2.3.1:../../net/rsync
DEPENDS+=		srsh-*:../../net/srsh

.include "../../mk/bsd.prefs.mk"

SSYNC_PAWD?=		pwd

NO_CONFIGURE=		yes
ALL_TARGET=		all PREFIX=${PREFIX} PAWD=${SSYNC_PAWD}
INSTALL_TARGET=		install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
