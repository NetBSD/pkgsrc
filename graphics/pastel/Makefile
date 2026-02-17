# $NetBSD: Makefile,v 1.10 2026/02/17 13:47:22 pin Exp $

DISTNAME=	pastel-0.12.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=sharkdp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sharkdp/pastel/
COMMENT=	Command-line tool to generate, analyze, convert and manipulate colors
LICENSE=	apache-2.0

.include "cargo-depends.mk"

RUST_REQ=		1.83.0
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/pastel \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
