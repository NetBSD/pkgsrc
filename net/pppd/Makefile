# $NetBSD: Makefile,v 1.13 2015/07/12 06:25:37 dholland Exp $

DISTNAME=		ppp-${PPPD_VERSION}
PKGNAME=		${DISTNAME:S/ppp/&d/}
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.samba.org/pub/ppp/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ppp.samba.org/
COMMENT=		PPP Daemon

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake

ONLY_FOR_PLATFORM+=	SunOS-*-* Linux-*-* NetBSD-*-* OpenBSD-*-* \
			MirBSD-*-* Bitrig-*-* FreeBSD-*-* DragonFly-*-*

PKG_SYSCONFSUBDIR=	ppp
CONFIGURE_ENV+=		PREFIX=${PREFIX:Q} PKGSYSCONFDIR=${PKG_SYSCONFDIR:Q}

PPPD_VERSION=	2.4.3
PLIST_SUBST+=	PPPD_VERSION=${PPPD_VERSION:Q}

DESTDIR_VARNAME=	#empty
INSTALL_MAKE_FLAGS+=	DESTDIR=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
