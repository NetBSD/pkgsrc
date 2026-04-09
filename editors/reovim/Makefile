# $NetBSD: Makefile,v 1.7 2026/04/09 17:16:54 pin Exp $

DISTNAME=	reovim-0.14.4
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=ds1sqe/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ds1sqe/reovim/
COMMENT=	Rust-powered neovim-like text editor
LICENSE=	gnu-agpl-v3

.include "cargo-depends.mk"

RUST_REQ=	1.92.0

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/reovim \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
