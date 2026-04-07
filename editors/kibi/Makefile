# $NetBSD: Makefile,v 1.9 2026/04/07 18:30:33 pin Exp $

DISTNAME=	kibi-0.3.3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=ilai-deutel/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ilai-deutel/kibi/
COMMENT=	Text editor in less than 1024 lines of code, written in Rust
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.93.0

# Depends on an unpublished crates. Can't use cargo.mk to fetch it.
TOKEI_REV=	d2101e530d4c97752ceec3dde2d942cc56ff8173

DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	tokei-${TOKEI_REV}.tar.gz

SITES.tokei-${TOKEI_REV}.tar.gz=	-${MASTER_SITE_GITHUB:=ilai-deutel/}tokei/archive/${TOKEI_REV}.tar.gz

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
