# $NetBSD: Makefile,v 1.20 2025/08/15 07:07:12 adam Exp $

.include "../../net/ldns/version.mk"

PKGNAME=	drill-${LDNS_VERSION}

MAINTAINER=	he@NetBSD.org
#HOMEPAGE=	http://www.nlnetlabs.nl/dnssec/drill.html
COMMENT=	DNSSEC debugging tool a'la dig
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

BUILD_TARGET=	all drill
INSTALL_TARGET=	install-drill

.include "../../net/ldns/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
