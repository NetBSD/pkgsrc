# $NetBSD: Makefile,v 1.15 2022/06/14 20:16:44 pin Exp $

DISTNAME=	dua-cli-2.17.7
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Byron/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Byron/dua-cli/
COMMENT=	View disk space usage and delete unwanted data
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Linux"
CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		tui-unix
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/dua \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
