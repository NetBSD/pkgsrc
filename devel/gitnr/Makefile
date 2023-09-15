# $NetBSD: Makefile,v 1.1 2023/09/15 06:28:36 pin Exp $

DISTNAME=	gitnr-0.1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=reemus-dev/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/reemus-dev/gitnr/
COMMENT=	Create gitignore files using one or more templates
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
