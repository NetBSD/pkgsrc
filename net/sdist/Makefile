# $NetBSD: Makefile,v 1.18 2013/03/14 17:23:12 kim Exp $
#

DISTNAME=		sdist-1.9
CATEGORIES=		net
MASTER_SITES=		http://oss.gw.com/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Invoke rdist to distribute files to a set of hosts

DEPENDS+=		netname-[0-9]*:../../net/netname
DEPENDS+=		osname-[0-9]*:../../sysutils/osname
DEPENDS+=		freerdist-[0-9]*:../../net/rdist6
DEPENDS+=		srsh-[0-9]*:../../net/srsh

.include "../../mk/bsd.prefs.mk"

SDIST_PAWD?=		pwd

BUILD_DEFS+=		SDIST_PAWD

EGDIR=			share/examples/${PKGBASE}

CONF_FILES=		${PREFIX}/${EGDIR}/${PKGBASE}.conf \
			${PKG_SYSCONFDIR}/${PKGBASE}.conf

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8 ${EGDIR}
NO_CONFIGURE=		yes
BUILD_MAKE_FLAGS+=	PAWD=${SDIST_PAWD}
INSTALL_MAKE_FLAGS+=	EGDIR=${EGDIR}
MAKE_FLAGS+=		PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
