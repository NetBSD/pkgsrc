# $NetBSD: Makefile,v 1.12 2026/08/17 07:15:22 pin Exp $

DISTNAME=	redox-0.8.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=JackDerksen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JackDerksen/redox/
COMMENT=	Terminal-based text editor, built with MinUI
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	share/examples/redox

#RUST_REQ=	1.98.0-beta.7
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.98.0-beta.7 on amd64

post-install:
	${INSTALL_DATA} ${WRKSRC}/config.example.toml \
		${DESTDIR}${PREFIX}/share/examples/redox

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
