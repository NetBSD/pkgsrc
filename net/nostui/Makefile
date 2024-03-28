# $NetBSD: Makefile,v 1.2 2024/03/28 21:37:00 wiz Exp $

DISTNAME=	nostui-0.1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=akiomik/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/akiomik/nostui/
COMMENT=	TUI client for Nostr
LICENSE=	mit

TOOL_DEPENDS+=	git-base-[0-9]*:../../devel/git-base

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
