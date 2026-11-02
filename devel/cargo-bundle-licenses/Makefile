# $NetBSD: Makefile,v 1.3 2026/11/02 16:02:04 pin Exp $

DISTNAME=	cargo-bundle-licenses-5.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sstadick/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/sstadick/cargo-bundle-licenses/
COMMENT=	Generate a THIRDPARTY file with all licenses in a cargo project
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

RUST_REQ=	1.88

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
