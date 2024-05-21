# $NetBSD: Makefile,v 1.9 2024/05/21 10:49:21 schmonz Exp $

DISTNAME=	twitch-tui-2.6.10
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=Xithrius/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://xithrius.github.io/twitch-tui/
COMMENT=	Twitch chat in the terminal
LICENSE=	apache-2.0 AND mit

RUST_REQ=	1.75.0

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
