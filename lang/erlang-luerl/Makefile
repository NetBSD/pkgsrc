# $NetBSD: Makefile,v 1.8 2026/02/15 18:22:32 gdt Exp $

DISTNAME=	luerl-1.2.3
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=rvirding/}
# Upstream does not publish NEWS:
#   https://github.com/rvirding/luerl/issues/178

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rvirding/luerl/
COMMENT=	Implementation of Lua in Erlang
LICENSE=	apache-2.0

GITHUB_PROJECT=	luerl
GITHUB_TAG=	v${PKGVERSION_NOREV}

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
