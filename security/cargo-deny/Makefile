# $NetBSD: Makefile,v 1.1 2026/05/28 11:26:52 adam Exp $

DISTNAME=	cargo-deny-0.19.8
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=EmbarkStudios/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/EmbarkStudios/cargo-deny
COMMENT=	Check project dependencies
LICENSE=	apache-2.0 # or MIT

RUST_REQ=	1.88.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
