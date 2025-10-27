# $NetBSD: Makefile,v 1.2 2025/10/27 12:01:13 pin Exp $

DISTNAME=	cargo-bundle-licenses-4.2.0
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
