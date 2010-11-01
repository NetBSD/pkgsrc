# $NetBSD: Makefile,v 1.9 2010/11/01 00:08:14 wiz Exp $

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

ONLY_FOR_PLATFORM+=	NetBSD-*-* Linux-*-* DragonFly*

PKG_SYSCONFSUBDIR=	ppp
CONFIGURE_ENV+=		PREFIX=${PREFIX:Q} PKGSYSCONFDIR=${PKG_SYSCONFDIR:Q}

PPPD_VERSION=	2.4.3
PLIST_SUBST+=	PPPD_VERSION=${PPPD_VERSION:Q}

.include "../../mk/bsd.pkg.mk"
