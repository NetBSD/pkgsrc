# $NetBSD: Makefile,v 1.1 2023/09/09 17:28:00 wiz Exp $

DISTNAME=	eza-0.11.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=eza-community/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eza-community/eza/
COMMENT=	Modern, maintained replacement for ls
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
