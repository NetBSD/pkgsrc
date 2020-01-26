# $NetBSD: Makefile,v 1.5 2020/01/26 17:32:02 rillig Exp $

DISTNAME=	credns-0.2.10
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/credns/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://www.nlnetlabs.nl/downloads/credns/
COMMENT=	Validates DNSSEC in the DNS notify/transfer-chain
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
