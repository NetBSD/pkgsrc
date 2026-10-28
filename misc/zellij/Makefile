# $NetBSD: Makefile,v 1.2 2026/10/28 18:00:41 pin Exp $

DISTNAME=	zellij-0.45.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=zellij-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zellij.dev/
COMMENT=	Terminal workspace with batteries included
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.95.0
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config gmake perl

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/applications

PREPEND_PATH+=	${PREFIX}/gnu/bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

# Use go-md2man to generate manpages and install them
post-install:
	${INSTALL_DATA} ${WRKSRC}/assets/zellij.desktop \
		${DESTDIR}${PREFIX}/share/applications

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
