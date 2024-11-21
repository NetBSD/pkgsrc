# $NetBSD: Makefile,v 1.7 2024/11/21 09:40:08 pin Exp $

DISTNAME=	gping-1.18.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=orf/}
GITHUB_TAG=	refs/tags/gping-v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/orf/gping/
COMMENT=	Ping, but with a graph
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=	${WRKDIR}/gping-gping-v${PKGVERSION_NOREV}

#RUST_REQ=		1.79.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.79.0 on amd64
USE_TOOLS+=		pkg-config
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/gping \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gping.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gping.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
