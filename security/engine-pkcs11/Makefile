# $NetBSD: Makefile,v 1.2 2009/06/08 19:11:30 hasso Exp $
#

DISTNAME=		engine_pkcs11-0.1.5
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		security
MASTER_SITES=		http://www.opensc-project.org/files/engine_pkcs11/

MAINTAINER=		hasso@NetBSD.org
HOMEPAGE=		http://www.opensc-project.org/engine_pkcs11/
COMMENT=		PKCS\#11 engine for OpenSSL
LICENSE=		original-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

.include "../../security/libp11/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
