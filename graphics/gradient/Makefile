# $NetBSD: Makefile,v 1.5 2025/05/08 11:42:44 pin Exp $

DISTNAME=	gradient-rs-0.4.1
PKGNAME=	gradient-0.4.1
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
