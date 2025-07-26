# $NetBSD: Makefile,v 1.1 2025/07/26 09:01:03 pin Exp $

DISTNAME=	lstr-0.2.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=bgreenwell/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bgreenwell/lstr/
COMMENT=	Fast, minimalist directory tree viewer
LICENSE=	mit

#RUST_REQ=		1.88.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.88.0 on amd64
USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	share/doc/lstr

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/lstr

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
