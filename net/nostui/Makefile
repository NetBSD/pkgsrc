# $NetBSD: Makefile,v 1.1 2024/01/20 06:57:39 pin Exp $

DISTNAME=	nostui-0.1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=akiomik/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/akiomik/nostui/
COMMENT=	TUI client for Nostr
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
