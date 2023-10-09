# $NetBSD: Makefile,v 1.1 2023/10/09 12:16:02 pin Exp $

DISTNAME=	cargo-upgrades-2.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=kornelski/}
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/kornelski/cargo-upgrades/
COMMENT=	Check for outdated dependencies in Rust/Cargo projects
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/cargo-upgrades-v2.0.0-9107370a2b2a559f5def95d87a0f38e32fa2de76

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
