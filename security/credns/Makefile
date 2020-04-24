# $NetBSD: Makefile,v 1.6 2020/04/24 11:41:36 nia Exp $

DISTNAME=	credns-0.2.10
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/credns/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://www.nlnetlabs.nl/downloads/credns/
COMMENT=	Validates DNSSEC in the DNS notify/transfer-chain
LICENSE=	modified-bsd

BROKEN=		"Fails to build with OpenSSL 1.1"

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
