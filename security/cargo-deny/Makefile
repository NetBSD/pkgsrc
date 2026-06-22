# $NetBSD: Makefile,v 1.2 2026/06/22 05:58:01 pin Exp $

DISTNAME=	cargo-deny-0.19.9
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
