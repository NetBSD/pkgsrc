# $NetBSD: Makefile,v 1.18 2023/10/24 22:10:14 wiz Exp $

VERSION=	1.7.1
DISTNAME=	ldns-${VERSION}
PKGNAME=	drill-${VERSION}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/ldns/

MAINTAINER=	he@NetBSD.org
#HOMEPAGE=	http://www.nlnetlabs.nl/dnssec/drill.html
COMMENT=	DNSSEC debugging tool a'la dig
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

BUILD_TARGET=	all drill
INSTALL_TARGET=	install-drill

BUILDLINK_API_DEPENDS.ldns+=	ldns>=${VERSION}

.include "../../net/ldns/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
