# $NetBSD: Makefile,v 1.33 2026/01/12 11:50:20 pin Exp $

DISTNAME=	csvlens-0.15.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=YS-L/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/YS-L/csvlens/
COMMENT=	Command line csv viewer
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.88.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
