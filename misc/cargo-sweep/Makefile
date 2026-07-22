# $NetBSD: Makefile,v 1.1 2026/07/22 13:35:48 adam Exp $

DISTNAME=	cargo-sweep-0.8.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=holmgr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/holmgr/cargo-sweep
COMMENT=	Delete old or unused build artifacts
LICENSE=	mit

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cargo-sweep ${DESTDIR}${PREFIX}/bin

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
