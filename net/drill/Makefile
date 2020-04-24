# $NetBSD: Makefile,v 1.16 2020/04/24 11:56:55 nia Exp $

VERSION=	1.6.17
DISTNAME=	ldns-${VERSION}
PKGNAME=	drill-${VERSION}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/ldns/

MAINTAINER=	he@NetBSD.org
#HOMEPAGE=	http://www.nlnetlabs.nl/dnssec/drill.html
COMMENT=	DNSSEC debugging tool a'la dig
LICENSE=	modified-bsd

BROKEN=		"Fails to build with OpenSSL 1.1"

USE_TOOLS+=	gmake

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-ldns=${BUILDLINK_PREFIX.ldns}
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

WRKSRC=		${WRKDIR}/${DISTNAME}/drill

BUILDLINK_API_DEPENDS.ldns+=	ldns>=${VERSION}

.include "../../net/ldns/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
