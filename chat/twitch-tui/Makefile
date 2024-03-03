# $NetBSD: Makefile,v 1.4 2024/03/03 19:52:18 schmonz Exp $

DISTNAME=		twitch-tui-2.6.5
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_GITHUB:=Xithrius/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://xithrius.github.io/twitch-tui/
COMMENT=		Twitch chat in the terminal
LICENSE=		apache-2.0 AND mit

RUST_REQ=		1.75.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
