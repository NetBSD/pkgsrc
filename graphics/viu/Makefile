# $NetBSD: Makefile,v 1.10 2025/12/10 08:32:27 pin Exp $

DISTNAME=	viu-1.6.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=atanunq/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/atanunq/viu/
COMMENT=	Simple terminal image viewer written in Rust
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
