# $NetBSD: Makefile,v 1.1 2021/12/21 15:10:51 wiz Exp $

DISTNAME=	taplo-lsp-0.2.6
CATEGORIES=	devel editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=tamasfe/}
GITHUB_PROJECT=	taplo
GITHUB_TAG=	release-lsp-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tamasfe/taplo/
COMMENT=	Language server protocol (LSP) for TOML
LICENSE=	mit

WRKSRC=		${WRKDIR}/taplo-${GITHUB_TAG}
USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

# as of 0.2.6, Cargo.lock is not in the repository
# so you need to do:
# cd ${WRKSRC} && cargo build
# before you can run 'make print-cargo-depends'
.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/taplo-lsp ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
