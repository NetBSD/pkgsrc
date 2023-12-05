# $NetBSD: Makefile,v 1.1 2023/12/05 16:04:13 schmonz Exp $

DISTNAME=		twitch-tui-2.6.1
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_GITHUB:=Xithrius/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://xithrius.github.io/twitch-tui/
COMMENT=		Twitch chat in the terminal
LICENSE=		apache-2.0 AND mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
