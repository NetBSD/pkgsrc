# $NetBSD: Makefile,v 1.20 2024/07/17 12:05:23 pin Exp $

DISTNAME=	dust-1.1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=bootandy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/bootandy/dust/
COMMENT=	More intuitive version of du in rust
LICENSE=	apache-2.0

.include "cargo-depends.mk"

RUST_REQ=		1.79.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.79.0 on amd64

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/examples/dust

post-install:
	${INSTALL_MAN} ${WRKSRC}/man-page/dust.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/dust.1
	${INSTALL_DATA} ${WRKSRC}/config/config.toml \
		${DESTDIR}${PREFIX}/share/examples/dust

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
