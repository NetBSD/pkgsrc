# $NetBSD: Makefile,v 1.11 2025/12/22 21:01:47 pin Exp $

DISTNAME=	chess-tui-2.2.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=thomas-mauran/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://thomas-mauran.github.io/chess-tui/
COMMENT=	Chess TUI implementation in rust
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config perl gmake

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.alsa-lib}/lib

DEPENDS+=	alsa-plugins-oss-[0-9]*:../../audio/alsa-plugins-oss

.include "../../lang/rust/cargo.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
