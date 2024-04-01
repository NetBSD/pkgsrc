# $NetBSD: Makefile,v 1.37 2024/04/01 19:17:34 pin Exp $

DISTNAME=	git-cliff-2.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=orhun/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/orhun/git-cliff/
COMMENT=	Highly customizable Changelog Generator
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libgit2}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/git-cliff \
		${DESTDIR}${PREFIX}/bin

.include "../../devel/libgit2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
