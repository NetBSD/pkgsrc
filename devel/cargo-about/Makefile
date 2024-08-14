# $NetBSD: Makefile,v 1.3 2024/08/14 09:32:17 pin Exp $

DISTNAME=	cargo-about-0.6.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=EmbarkStudios/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/EmbarkStudios/cargo-about/
COMMENT=	Cargo plugin to generate list of all licenses for a crate
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

RUST_REQ=	1.74.0
USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
