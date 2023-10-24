# $NetBSD: Makefile,v 1.2 2023/10/24 22:10:03 wiz Exp $

DISTNAME=	projectable-1.3.0
PKGREVISION=	1
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
