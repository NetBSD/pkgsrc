# $NetBSD: Makefile,v 1.47 2025/02/02 18:10:08 pin Exp $

DISTNAME=	git-cliff-2.7.0
# git-cliff-2.8.0 requires Rust >= 1.83
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=orhun/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/orhun/git-cliff/
COMMENT=	Highly customizable Changelog Generator
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

RUST_REQ=		1.82.0
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/git-cliff \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
