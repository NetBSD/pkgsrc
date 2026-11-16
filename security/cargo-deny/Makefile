# $NetBSD: Makefile,v 1.4 2026/11/16 17:02:35 adam Exp $

DISTNAME=	cargo-deny-0.21.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=EmbarkStudios/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/EmbarkStudios/cargo-deny
COMMENT=	Check project dependencies
LICENSE=	apache-2.0 OR mit

RUST_REQ=	1.89.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
