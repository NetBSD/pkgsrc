# $NetBSD: Makefile,v 1.25 2025/04/02 10:58:27 pin Exp $

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

# See, https://github.com/briansmith/ring/issues/1999
NOT_FOR_PLATFORM+=	*-*-i386

.include "cargo-depends.mk"

RUST_REQ=	1.74.0
USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
