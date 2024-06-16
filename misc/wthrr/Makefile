# $NetBSD: Makefile,v 1.23 2024/06/16 04:52:25 pin Exp $

DISTNAME=	wthrr-the-weathercrab-1.2.0
PKGNAME=	wthrr-1.2.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ttytm/}
GITHUB_PROJECT=	wthrr-the-weathercrab
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/ttytm/wthrr-the-weathercrab/
COMMENT=	Little helper for your terminal who knows about the weather
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
