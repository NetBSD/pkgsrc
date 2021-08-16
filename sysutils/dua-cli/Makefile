# $NetBSD: Makefile,v 1.2 2021/08/16 13:04:52 pin Exp $

DISTNAME=	dua-cli-2.14.4
# Do not update this package. Newer versions require Rust>=1.54.0
# in order to build clap-3.0.0-beta.4
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
