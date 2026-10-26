# $NetBSD: Makefile,v 1.2 2026/10/26 11:25:44 pin Exp $

DISTNAME=	brochure-0.12.0
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_GITHUB:=Sylviromi/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Sylviromi/brochure/
COMMENT=	Terminal RSS reader built with Ratatui
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.95.0
USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
