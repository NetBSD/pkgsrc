# $NetBSD: Makefile,v 1.14 2025/10/26 08:36:12 adam Exp $

DISTNAME=	cargo-upgrades-2.2.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=kornelski/}
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/kornelski/cargo-upgrades/
COMMENT=	Check for outdated dependencies in Rust/Cargo projects
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/cargo-upgrades-v2.2.4-4d18359ba87cd7ccb2fd0d9c975b2d85d5cb7e9c

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

RUST_REQ=	1.85.0
USE_LANGUAGES=	c c++

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"
# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"
.include "../../mk/bsd.pkg.mk"
