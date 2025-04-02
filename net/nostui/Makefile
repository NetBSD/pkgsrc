# $NetBSD: Makefile,v 1.3 2025/04/02 11:01:13 pin Exp $

DISTNAME=	nostui-0.1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=akiomik/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/akiomik/nostui/
COMMENT=	TUI client for Nostr
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
NOT_FOR_PLATFORM+=	*-*-i386

TOOL_DEPENDS+=	git-base-[0-9]*:../../devel/git-base

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
