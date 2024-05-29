# $NetBSD: Makefile,v 1.19 2024/05/29 16:33:59 adam Exp $

DISTNAME=	ncgopher-0.6.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=jansc/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/jansc/ncgopher/
COMMENT=	Gopher and gemini client for the modern internet
LICENSE=	2-clause-bsd

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.ncurses}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ncgopher \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ncgopher.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
