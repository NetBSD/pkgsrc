# $NetBSD: Makefile,v 1.9 2025/01/24 21:22:30 pin Exp $

DISTNAME=	cargo-upgrades-2.1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=kornelski/}
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/kornelski/cargo-upgrades/
COMMENT=	Check for outdated dependencies in Rust/Cargo projects
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/cargo-upgrades-v2.1.3-87c78ffc5a9b7a9112bfa98dd7b1756a11a086e3

RUST_REQ=	1.70.0
USE_LANGUAGES+=	c c++

.include "../../lang/rust/cargo.mk"
BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
