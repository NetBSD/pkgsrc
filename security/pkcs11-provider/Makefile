# $NetBSD: Makefile,v 1.3 2026/11/03 14:47:35 riastradh Exp $

DISTNAME=	pkcs11-provider-1.3.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=openssl-projects/pkcs11-provider/releases/download/v1.3.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openssl-projects/pkcs11-provider
COMMENT=	OpenSSL provider for PKCS\#11 modules
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config

MESON_ARGS+=	${${USE_BUILTIN.openssl} == "yes":?-Dmodules_dir=${PREFIX:Q}/lib/ossl-modules:}

.include "../../devel/meson/build.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
