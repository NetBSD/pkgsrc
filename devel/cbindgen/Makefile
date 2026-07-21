# $NetBSD: Makefile,v 1.42 2026/07/21 16:45:36 wiz Exp $

DISTNAME=	cbindgen-0.29.4
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
