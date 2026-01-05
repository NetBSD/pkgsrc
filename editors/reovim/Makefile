# $NetBSD: Makefile,v 1.2 2026/01/05 06:07:16 pin Exp $

DISTNAME=	reovim-0.7.8
# reovim >= 0.7.9 requires Rust >= 1.92
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=ds1sqe/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ds1sqe/reovim/
COMMENT=	Rust-powered neovim-like text editor
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/reovim \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
