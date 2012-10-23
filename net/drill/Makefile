# $NetBSD: Makefile,v 1.7 2012/10/23 17:18:18 asau Exp $

VERSION=	1.6.13
DISTNAME=	ldns-${VERSION}
PKGNAME=	drill-${VERSION}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/ldns/

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://www.nlnetlabs.nl/dnssec/drill.html
COMMENT=	DNSSEC debugging tool a'la dig
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-ldns=${PREFIX}

WRKSRC=		${WRKDIR}/${DISTNAME}/drill

BUILDLINK_API_DEPENDS.ldns+=    ldns>=${VERSION}

.include "../../net/ldns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
