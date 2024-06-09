# $NetBSD: Makefile,v 1.13 2024/06/09 14:04:28 wiz Exp $

DISTNAME=	jj-0.18.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=martinvonz/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/martinvonz/jj/
COMMENT=	Git-compatible DVCS that is both simple and powerful
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/jj \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
