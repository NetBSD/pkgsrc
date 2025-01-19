# $NetBSD: Makefile,v 1.37 2025/01/19 19:29:38 wiz Exp $

DISTNAME=	cbindgen-0.28.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mozilla/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/cbindgen
COMMENT=	Generating C bindings from Rust code
LICENSE=	mpl-2.0

.include "cargo-depends.mk"

RUST_RUNTIME=	yes
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
