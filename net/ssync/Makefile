# $NetBSD: Makefile,v 1.9 2007/03/24 19:21:30 joerg Exp $
#

DISTNAME=		ssync-1.6
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Invoke rsync to distribute files to a set of hosts

DEPENDS+=		netname-[0-9]*:../../net/netname
DEPENDS+=		osname-[0-9]*:../../sysutils/osname
DEPENDS+=		rsync>=2.3.1:../../net/rsync
DEPENDS+=		srsh-[0-9]*:../../net/srsh

.include "../../mk/bsd.prefs.mk"

SSYNC_PAWD?=		pwd

NO_CONFIGURE=		yes
BUILD_TARGET=		all PREFIX=${PREFIX} PAWD=${SSYNC_PAWD}
INSTALL_TARGET=		install PREFIX=${PREFIX}
INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
