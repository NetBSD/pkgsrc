# $NetBSD: Makefile,v 1.10 2016/03/05 11:29:20 jperkin Exp $
#

VERSION=		0.1.8
DISTNAME=		engine_pkcs11-${VERSION}
PKGNAME=		${DISTNAME:S/_/-/}
PKGREVISION=		5
CATEGORIES=		security
MASTER_SITES=		https://github.com/OpenSC/engine_pkcs11/archive/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/OpenSC/OpenSC/wiki/OpenSSL-engine-for-PKCS%2311-modules
COMMENT=		PKCS\#11 engine for OpenSSL
LICENSE=		original-bsd

WRKSRC=			${WRKDIR}/engine_pkcs11-engine_pkcs11-${VERSION}

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7

USE_TOOLS+=		autoconf automake gmake pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
USE_PKGLOCALEDIR=	yes

pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include "../../security/libp11/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
