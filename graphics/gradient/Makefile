# $NetBSD: Makefile,v 1.4 2025/04/02 17:46:11 pin Exp $

DISTNAME=	gradient-rs-0.4.0
PKGNAME=	gradient-0.4.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=mazznoer/}
GITHUB_PROJECT=	gradient-rs
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mazznoer/gradient-rs/
COMMENT=	CLI tool for playing with color gradients
LICENSE=	apache-2.0 AND mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
