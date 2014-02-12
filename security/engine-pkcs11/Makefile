# $NetBSD: Makefile,v 1.8 2014/02/12 23:18:31 tron Exp $
#

DISTNAME=		engine_pkcs11-0.1.5
PKGNAME=		${DISTNAME:S/_/-/}
PKGREVISION=		4
CATEGORIES=		security
MASTER_SITES=		http://www.opensc-project.org/files/engine_pkcs11/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.opensc-project.org/engine_pkcs11/
COMMENT=		PKCS\#11 engine for OpenSSL
LICENSE=		original-bsd

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

.include "../../security/libp11/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
