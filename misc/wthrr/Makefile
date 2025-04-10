# $NetBSD: Makefile,v 1.26 2025/04/10 13:24:01 pin Exp $

DISTNAME=	wthrr-the-weathercrab-1.2.1
PKGNAME=	wthrr-1.2.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ttytm/}
GITHUB_PROJECT=	wthrr-the-weathercrab
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/ttytm/wthrr-the-weathercrab/
COMMENT=	Little helper for your terminal who knows about the weather
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.74.0
USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
