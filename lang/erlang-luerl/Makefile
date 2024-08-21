# $NetBSD: Makefile,v 1.6 2024/08/21 12:30:59 gdt Exp $

DISTNAME=	luerl-1.2.0
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
