# $NetBSD: Makefile,v 1.2 2026/11/16 06:06:52 adam Exp $

DISTNAME=	cargo-machete-0.10.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=bnjbvr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bnjbvr/cargo-machete
COMMENT=	Remove unused Rust dependencies
LICENSE=	mit

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cargo-machete ${DESTDIR}${PREFIX}/bin

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
