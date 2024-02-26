# $NetBSD: Makefile,v 1.17.20.1 2024/02/26 20:13:05 he Exp $

.include "../../net/ldns/version.mk"

VERSION=	${LDNS_VERSION}
DISTNAME=	ldns-${VERSION}
PKGNAME=	drill-${VERSION}
CATEGORIES=	net
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/ldns/

MAINTAINER=	he@NetBSD.org
#HOMEPAGE=	http://www.nlnetlabs.nl/dnssec/drill.html
COMMENT=	DNSSEC debugging tool a'la dig
LICENSE=	modified-bsd

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

BUILD_TARGET=	all drill
INSTALL_TARGET=	install-drill

BUILDLINK_API_DEPENDS.ldns+=	ldns>=${VERSION}

.include "../../net/ldns/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
