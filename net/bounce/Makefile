# $NetBSD: Makefile,v 1.3 2003/03/29 12:41:54 jmmv Exp $
#

DISTNAME=		bounce-0.0
WRKSRC=			${WRKDIR}/bounce
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		p99dreyf@criens.u-psud.fr
COMMENT=		tool to forward TCP connection from one IP to another

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

ALL_TARGET=		bounce

post-install:
	strip ${PREFIX}/bin/bounce

.include "../../mk/bsd.pkg.mk"
