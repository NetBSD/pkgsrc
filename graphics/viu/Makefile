# $NetBSD: Makefile,v 1.8 2023/11/22 12:57:26 pin Exp $

DISTNAME=	viu-1.5.0
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
