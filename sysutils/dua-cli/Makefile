# $NetBSD: Makefile,v 1.52 2026/07/30 21:24:09 pin Exp $

DISTNAME=	dua-cli-2.39.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Byron/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Byron/dua-cli/
COMMENT=	View disk space usage and delete unwanted data
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.98.0-beta.5
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.98.0-beta.5 on amd64

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/dua \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
