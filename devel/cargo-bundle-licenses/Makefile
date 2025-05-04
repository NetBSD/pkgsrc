# $NetBSD: Makefile,v 1.1 2025/05/04 15:27:52 pin Exp $

DISTNAME=	cargo-bundle-licenses-4.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sstadick/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/sstadick/cargo-bundle-licenses/
COMMENT=	Generate a THIRDPARTY file with all licenses in a cargo project
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
