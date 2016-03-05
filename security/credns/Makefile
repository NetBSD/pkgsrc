# $NetBSD: Makefile,v 1.3 2016/03/05 11:29:19 jperkin Exp $

DISTNAME=	credns-0.2.10
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/credns/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.nlnetlabs.nl/downloads/credns/
COMMENT=	Validates DNSSEC in the DNS notify/transfer-chain
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
