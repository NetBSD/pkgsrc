# $NetBSD: Makefile,v 1.13 2013/03/14 16:36:48 kim Exp $
#

DISTNAME=		ssync-1.9.1
CATEGORIES=		net
MASTER_SITES=		http://oss.gw.com/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Invoke rsync to distribute files to a set of hosts

DEPENDS+=		netname-[0-9]*:../../net/netname
DEPENDS+=		osname-[0-9]*:../../sysutils/osname
DEPENDS+=		rsync>=2.3.1:../../net/rsync
DEPENDS+=		srsh-[0-9]*:../../net/srsh

.include "../../mk/bsd.prefs.mk"

SSYNC_PAWD?=		pwd

BUILD_DEFS+=		SSYNC_PAWD

EGDIR=			share/examples/${PKGBASE}

CONF_FILES=		${PREFIX}/${EGDIR}/${PKGBASE}.conf \
			${PKG_SYSCONFDIR}/${PKGBASE}.conf

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8 ${EGDIR}
NO_CONFIGURE=		yes
BUILD_MAKE_FLAGS+=	PAWD=${SSYNC_PAWD}
INSTALL_MAKE_FLAGS+=	EGDIR=${EGDIR}
MAKE_FLAGS+=		PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
