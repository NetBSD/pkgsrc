# $NetBSD: Makefile,v 1.17 2004/02/15 18:47:04 itojun Exp $

DISTNAME=	nsd-2.0.0
CATEGORIES=	net
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nlnetlabs.nl/nsd/index.html
COMMENT=	Authoritative-only DNS server

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
