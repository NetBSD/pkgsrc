# $NetBSD: Makefile,v 1.2 2026/10/31 23:14:09 wiz Exp $

DISTNAME=	pkcs11-provider-1.3.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=openssl-projects/pkcs11-provider/releases/download/v1.3.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openssl-projects/pkcs11-provider
COMMENT=	OpenSSL provider for PKCS\#11 modules
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config

# as of 2026-10-31, does not work with base openssl
# a) the pkgsrc framework does not provide all required pkg-config values
#    in the faked libcrypto.pc file
# b) the base system does not provide the directories to install into
USE_BUILTIN.openssl=	no
.include "../../devel/meson/build.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
