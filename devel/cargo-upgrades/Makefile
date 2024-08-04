# $NetBSD: Makefile,v 1.2 2024/08/04 17:45:27 pin Exp $

DISTNAME=	cargo-upgrades-2.1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=kornelski/}
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/kornelski/cargo-upgrades/
COMMENT=	Check for outdated dependencies in Rust/Cargo projects
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/cargo-upgrades-v2.1.2-d890d43432610221d593216a68f0c14d7df4ccd7

RUST_REQ=	1.70.0
USE_LANGUAGES+=	c c++

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
