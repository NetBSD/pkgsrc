# $NetBSD: Makefile,v 1.3 2024/09/01 15:56:08 pin Exp $

DISTNAME=	gradient-rs-0.4.0
PKGNAME=	gradient-0.4.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=mazznoer/}
GITHUB_PROJECT=	gradient-rs
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/mazznoer/gradient-rs/
COMMENT=	CLI tool for playing with color gradients
LICENSE=	apache-2.0 AND mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
