# $NetBSD: Makefile,v 1.18 2024/10/10 10:34:31 jperkin Exp $

DISTNAME=	mktool-1.3.4
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=jperkin/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jperkin@pkgsrc.org
HOMEPAGE=	https://github.com/jperkin/mktool/
COMMENT=	High performance alternatives for pkgsrc/mk
LICENSE=	isc

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

RUST_REQ=	1.74.0

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
