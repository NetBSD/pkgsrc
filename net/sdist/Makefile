# $NetBSD: Makefile,v 1.13 2007/12/24 08:34:51 obache Exp $
#

DISTNAME=		sdist-1.7
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Invoke rdist to distribute files to a set of hosts

DEPENDS+=		netname-[0-9]*:../../net/netname
DEPENDS+=		osname-[0-9]*:../../sysutils/osname
DEPENDS+=		freerdist-[0-9]*:../../net/rdist6
DEPENDS+=		srsh-[0-9]*:../../net/srsh

.include "../../mk/bsd.prefs.mk"

SDIST_PAWD?=		pwd

BUILD_DEFS+=		SDIST_PAWD

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8
NO_CONFIGURE=		yes
BUILD_MAKE_FLAGS+=	PREFIX=${PREFIX} PAWD=${SDIST_PAWD}
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	post-extract
SUBST_FILES.manpath=	Makefile
SUBST_SED.manpath=	-e 's,/man/,/${PKGMANDIR}/,'

.include "../../mk/bsd.pkg.mk"
