# $NetBSD: Makefile,v 1.1 2026/07/22 13:34:30 adam Exp $

DISTNAME=	cargo-machete-0.9.2
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
