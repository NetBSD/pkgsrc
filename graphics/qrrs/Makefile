# $NetBSD: Makefile,v 1.10 2024/08/16 03:35:04 pin Exp $

DISTNAME=	qrrs-0.1.10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=Lenivaya/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Lenivaya/qrrs/
COMMENT=	CLI tool for working with qr-codes
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.79.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.79.0 on amd64

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/qrrs \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/qrrs.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
