# $NetBSD: Makefile,v 1.5 2024/11/30 20:12:24 wiz Exp $

DISTNAME=	hex-2.1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=hexpm/}
GITHUB_PROJECT=	hex
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hexpm/hex/
COMMENT=	Package manager for the Erlang VM
LICENSE=	apache-2.0

ELIXIR_APP_NAME=	hex
# NOTE: this seems to download files over the network
# TODO: fix!
MIX_TARGET=		local.hex --force

.include "../../lang/elixir/mix.mk"
.include "../../mk/bsd.pkg.mk"
