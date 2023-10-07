# $NetBSD: Makefile,v 1.5 2023/10/07 15:22:28 pin Exp $

DISTNAME=	bandsnatch-0.3.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Ovyerus/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Ovyerus/bandsnatch/
COMMENT=	CLI batch downloader for your Bandcamp collection
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl gmake

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
