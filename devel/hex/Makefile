# $NetBSD: Makefile,v 1.4 2023/03/03 10:10:38 wiz Exp $

DISTNAME=	hex-2.0.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=hexpm/}
GITHUB_PROJECT=	hex
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hexpm/hex/
COMMENT=	Package manager for the Erlang VM
LICENSE=	apache-2.0

ELIXIR_APP_NAME=	hex
ELIXIR_APP_VERSION=	2.0.6
# does this pull in dependencies over the network?
MIX_TARGET=		local.hex --force

.include "../../lang/elixir/mix.mk"
.include "../../mk/bsd.pkg.mk"
