# $NetBSD: Makefile,v 1.4 2003/07/21 17:10:24 martti Exp $
#

DISTNAME=		bounce-0.0
WRKSRC=			${WRKDIR}/bounce
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		p99dreyf@criens.u-psud.fr
COMMENT=		Tool to forward TCP connection from one IP to another

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

ALL_TARGET=		bounce

post-install:
	strip ${PREFIX}/bin/bounce

.include "../../mk/bsd.pkg.mk"
