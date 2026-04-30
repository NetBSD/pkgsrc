# $NetBSD: Makefile,v 1.6 2026/04/30 07:10:50 adam Exp $

DISTNAME=	sccache-0.15.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mozilla/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/sccache
COMMENT=	Shared compilation cache
LICENSE=	apache-2.0

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/sccache ${DESTDIR}${PREFIX}/bin/

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
