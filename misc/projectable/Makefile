# $NetBSD: Makefile,v 1.3 2025/07/22 11:30:40 he Exp $

DISTNAME=	projectable-1.3.0
PKGREVISION=	2
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
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
