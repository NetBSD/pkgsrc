# $NetBSD: Makefile,v 1.5 2021/12/10 17:19:49 pin Exp $

DISTNAME=	felix-0.2.12
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=kyoheiu/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/kyoheiu/felix/
COMMENT=	TUI file manager with vim-like key mapping
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/fx ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
