# $NetBSD: Makefile,v 1.11 2025/04/08 00:25:02 gdt Exp $

DISTNAME=	cargo-upgrades-2.1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=kornelski/}
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/kornelski/cargo-upgrades/
COMMENT=	Check for outdated dependencies in Rust/Cargo projects
LICENSE=	gnu-gpl-v3

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/cargo-upgrades-v2.1.3-87c78ffc5a9b7a9112bfa98dd7b1756a11a086e3

RUST_REQ=	1.70.0
USE_LANGUAGES+=	c c++

.include "../../lang/rust/cargo.mk"
BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
