# $NetBSD: Makefile,v 1.9 2022/03/20 16:24:01 pin Exp $

DISTNAME=	dua-cli-2.17.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Byron/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Byron/dua-cli/
COMMENT=	View disk space usage and delete unwanted data
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		tui-unix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/dua ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
