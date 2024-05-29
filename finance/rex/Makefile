# $NetBSD: Makefile,v 1.9 2024/05/29 16:32:31 adam Exp $

DISTNAME=	rex-0.1.16
PKGREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=TheRustyPickle/}
GITHUB_PROJECT=	Rex
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/TheRustyPickle/Rex/
COMMENT=	TUI for keeping track of incomes and expenses
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config
MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
