# $NetBSD: Makefile,v 1.22 2026/02/26 12:53:02 pin Exp $

DISTNAME=	matugen-4.0.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=InioX/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/InioX/matugen/
COMMENT=	Material you color generation tool
LICENSE=	gnu-gpl-v2

.include "cargo-depends.mk"

#RUST_REQ=	1.93.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.93.1 on amd64

INSTALLATION_DIRS=	share/examples/matugen

post-install:
	${INSTALL_DATA} ${WRKSRC}/example/config.toml \
		${DESTDIR}${PREFIX}/share/examples/matugen

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
