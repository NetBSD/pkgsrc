# $NetBSD: Makefile,v 1.11 2024/11/10 21:27:14 pin Exp $

DISTNAME=	v13.0.0-alpha.7
PKGNAME=	${GITHUB_PROJECT}-13.0.0.alpha7
CATEGORIES=	devel textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=XAMPPRocky/}
GITHUB_PROJECT=	tokei
GITHUB_TAG=	v13.0.0-alpha.7

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/XAMPPRocky/tokei/
COMMENT=	Displays statistics about code
LICENSE=	apache-2.0 AND mit

.include "cargo-depends.mk"

#RUST_REQ=		1.82.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.82.0 on amd64
USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tokei \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
