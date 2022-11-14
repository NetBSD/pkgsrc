# $NetBSD: Makefile,v 1.3 2022/11/14 17:48:14 nikita Exp $

DISTNAME=	hex-2.0.0
PKGREVISION=	1
PKGNAME=	elixir-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=hexpm/}
GITHUB_PROJECT=	hex
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hexpm/hex/
COMMENT=	Package manager for the Erlang VM
LICENSE=	apache-2.0

ELIXIR_APP_NAME=	hex
# does this pull in dependencies over the network?
MIX_TARGET=		local.hex --force

.include "../../lang/elixir/mix.mk"
.include "../../mk/bsd.pkg.mk"
