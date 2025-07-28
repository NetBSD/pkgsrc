# $NetBSD: Makefile,v 1.16 2025/07/28 10:58:15 pin Exp $

DISTNAME=	parallel-disk-usage-0.20.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=KSXGitHub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KSXGitHub/parallel-disk-usage/
COMMENT=	Highly parallelized, blazing fast directory tree analyzer
LICENSE=	apache-2.0

.include "cargo-depends.mk"

#RUST_REQ=	1.88.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.88.0 on amd64
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/pdu \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
