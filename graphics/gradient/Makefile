# $NetBSD: Makefile,v 1.2 2024/02/02 12:35:56 pin Exp $

DISTNAME=	gradient-rs-0.3.4
PKGNAME=	gradient-0.3.4
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
