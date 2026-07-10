# $NetBSD: Makefile,v 1.3 2026/07/10 12:03:07 adam Exp $

DISTNAME=	cargo-deny-0.20.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=EmbarkStudios/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/EmbarkStudios/cargo-deny
COMMENT=	Check project dependencies
LICENSE=	apache-2.0 OR mit

RUST_REQ=	1.88.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
