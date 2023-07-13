# $NetBSD: Makefile,v 1.51 2023/07/13 20:34:02 pin Exp $

DISTNAME=	felix-2.5.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=kyoheiu/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://kyoheiu.dev/felix/
COMMENT=	TUI file manager with vim-like key mapping
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	share/examples/felix

post-install:
	${INSTALL_DATA} ${WRKSRC}/config.yaml \
		${DESTDIR}${PREFIX}/share/examples/felix

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
