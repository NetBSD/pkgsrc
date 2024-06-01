# $NetBSD: Makefile,v 1.2 2024/06/01 14:11:13 pin Exp $

DISTNAME=	cargo-about-0.6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=EmbarkStudios/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/EmbarkStudios/cargo-about/
COMMENT=	Cargo plugin to generate list of all licenses for a crate
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
