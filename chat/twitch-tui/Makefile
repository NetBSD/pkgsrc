# $NetBSD: Makefile,v 1.3 2023/12/29 00:45:05 schmonz Exp $

DISTNAME=		twitch-tui-2.6.2
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_GITHUB:=Xithrius/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://xithrius.github.io/twitch-tui/
COMMENT=		Twitch chat in the terminal
LICENSE=		apache-2.0 AND mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
