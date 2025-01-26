# $NetBSD: Makefile,v 1.21 2025/01/26 15:17:07 pin Exp $

DISTNAME=	bacon-3.9.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Canop/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://dystroy.org/bacon/
COMMENT=	Background rust code check
LICENSE=	gnu-agpl-v3

.include "cargo-depends.mk"

RUST_REQ=	1.76.0

CARGO_NO_DEFAULT_FEATURES=	YES

# As of version 3.9.0, bacon has a sound feature that uses rodio.
# rodio needs alsa to output sound hence, '--no-default-features' above.
# If you wish to build bacon with audio support, comment out the line
# CARGO_NO_DEFAULT_FEATURES=	YES
# and uncomment the lines below.
#USE_TOOLS+=	pkg-config
#RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.alsa-lib}/lib
#DEPENDS+=	alsa-plugins-oss-[0-9]*:../../audio/alsa-plugins-oss
#.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
