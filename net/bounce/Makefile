# $NetBSD: Makefile,v 1.9 2006/11/19 08:03:05 wiz Exp $
#

DISTNAME=		bounce-0.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		manu@NetBSD.org
COMMENT=		Tool to forward TCP connection from one IP to another

CONFLICTS+=		majordomo-*

WRKSRC=			${WRKDIR}/bounce
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

BUILD_TARGET=		bounce

post-install:
	strip ${PREFIX}/bin/bounce

.include "../../mk/bsd.pkg.mk"
