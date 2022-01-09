# $NetBSD: Makefile,v 1.7 2022/01/09 09:24:33 pin Exp $

DISTNAME=	dua-cli-2.16.0
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
