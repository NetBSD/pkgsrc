# $NetBSD: Makefile,v 1.2 2001/02/17 18:18:38 wiz Exp $
#

DISTNAME=		bounce-0.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		p99dreyf@criens.u-psud.fr
COMMENT=		tool to forward TCP connection from one IP to another

WRKSRC=			${WRKDIR}/bounce

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

ALL_TARGET=		bounce

post-install:
	strip ${PREFIX}/bin/bounce

.include "../../mk/bsd.pkg.mk"
