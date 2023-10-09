# $NetBSD: Makefile,v 1.9 2023/10/09 08:10:38 pin Exp $

DISTNAME=	tui-journal-0.3.3
CATEGORIES=	misc
MASTER_SITES=	https://static.crates.io/crates/tui-journal/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ammarabouzor/tui-journal/
COMMENT=	Your journal app if you live in a terminal
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
