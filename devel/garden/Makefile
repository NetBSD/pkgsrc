# $NetBSD: Makefile,v 1.21 2025/02/24 08:36:39 pin Exp $

DISTNAME=	garden-2.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v2.1.0/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

SITES.spirv-0.3.0+sdk-1.3.268.0.crate=	https://static.crates.io/crates/spirv/

.include "cargo-depends.mk"

RUST_REQ=	1.74.0

WRKSRC=		${WRKDIR}/garden-v2.1.0-61076c0d702d459883b40d95de959ca499d94757

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
