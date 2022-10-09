# $NetBSD: Makefile,v 1.1 2022/10/09 16:08:18 pin Exp $

DISTNAME=	repofetch-0.3.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=spenserblack/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spenserblack/repofetch/
COMMENT=	Fetch details about your remote repository
LICENSE=	apache-2.0 AND mit

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libgit2}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/repofetch \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
