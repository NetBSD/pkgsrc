# $NetBSD: Makefile,v 1.2 2023/09/11 08:01:59 pin Exp $

DISTNAME=	flip-link-0.1.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=knurling-rs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/knurling-rs/flip-link/
COMMENT=	Zero-cost stack overflow protection for embedded programs
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
