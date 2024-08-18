# $NetBSD: Makefile,v 1.5 2024/08/18 06:38:13 wiz Exp $

DISTNAME=	cargo-upgrades-2.1.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=kornelski/}
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/kornelski/cargo-upgrades/
COMMENT=	Check for outdated dependencies in Rust/Cargo projects
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/cargo-upgrades-v2.1.2-d890d43432610221d593216a68f0c14d7df4ccd7

RUST_REQ=	1.70.0
USE_LANGUAGES+=	c c++

.include "../../lang/rust/cargo.mk"
BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
