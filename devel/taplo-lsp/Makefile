# $NetBSD: Makefile,v 1.3 2023/10/24 22:08:58 wiz Exp $

DISTNAME=	taplo-cli-0.6.0
PKGREVISION=	1
CATEGORIES=	devel editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=tamasfe/}
GITHUB_PROJECT=	taplo
GITHUB_TAG=	release-cli-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tamasfe/taplo/
COMMENT=	Language server protocol (LSP) for TOML
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

# as of 0.6.0, Cargo.lock is not in the repository
# so you need to do:
# cd ${WRKSRC} && cargo build
# before you can run 'make print-cargo-depends'
.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/taplo ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
