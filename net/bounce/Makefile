# $NetBSD: Makefile,v 1.5 2004/01/20 12:22:18 agc Exp $
#

DISTNAME=		bounce-0.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		p99dreyf@criens.u-psud.fr
COMMENT=		Tool to forward TCP connection from one IP to another

WRKSRC=			${WRKDIR}/bounce
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

ALL_TARGET=		bounce

post-install:
	strip ${PREFIX}/bin/bounce

.include "../../mk/bsd.pkg.mk"
