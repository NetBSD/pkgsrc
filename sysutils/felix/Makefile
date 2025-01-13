# $NetBSD: Makefile,v 1.65 2025/01/13 20:28:18 pin Exp $

DISTNAME=	felix-2.16.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=kyoheiu/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://kyoheiu.dev/felix/
COMMENT=	TUI file manager with vim-like key mapping
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.78.0

INSTALLATION_DIRS=	share/examples/felix

post-install:
	${INSTALL_DATA} ${WRKSRC}/config.yaml \
		${DESTDIR}${PREFIX}/share/examples/felix

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
