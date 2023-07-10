# $NetBSD: Makefile,v 1.1 2023/07/10 19:51:05 pin Exp $

DISTNAME=	projectable-1.3.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=dzfrias/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dzfrias.dev/blog/projectable/
COMMENT=	TUI file manager built for projects
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl gmake

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
