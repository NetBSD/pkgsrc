# $NetBSD: Makefile,v 1.6 2026/11/25 06:31:57 adam Exp $

DISTNAME=	cargo-deny-0.22.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=EmbarkStudios/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/EmbarkStudios/cargo-deny
COMMENT=	Check project dependencies
LICENSE=	apache-2.0 OR mit

RUST_REQ=	1.95.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
