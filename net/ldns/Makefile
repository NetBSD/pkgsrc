# $NetBSD: Makefile,v 1.52 2025/08/15 07:07:11 adam Exp $

.include "../../net/ldns/version.mk"

PKGNAME=	${DISTNAME:S/-rc./rc/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://www.nlnetlabs.nl/projects/ldns/about/
COMMENT=	Library for simplified DNS programming
LICENSE=	modified-bsd

USE_TOOLS+=		gmake perl
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gost
CONFIGURE_ARGS+=	--enable-rrtype-svcb-https
CONFIGURE_ARGS+=	--enable-sha2
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-examples
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
CONFIGURE_ARGS+=	DOXYGEN=${FALSE:Q}

REPLACE_PERL=	doc/doxyparse.pl

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
