# $NetBSD: Makefile,v 1.3 2024/10/18 08:50:40 pin Exp $

DISTNAME=	moccasin-0.1.3
CATEGORIES=	news
MASTER_SITES=	https://static.crates.io/crates/moccasin/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rektdeckard/moccasin/
COMMENT=	TUI feed reader for RSS, Atom and (aspirationally) Podcasts
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
