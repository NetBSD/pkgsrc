# $NetBSD: Makefile,v 1.1 2022/11/10 12:24:08 nikita Exp $

DISTNAME=	hex-2.0.0
PKGNAME=	elixir-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=hexpm/}
GITHUB_PROJECT=	hex
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hexpm/hex/
COMMENT=	Package manager for the Erlang VM
LICENSE=	apache-2.0

DEPENDS+=	elixir>=1.14.0:../../lang/elixir

EBIN_DIR=	${DESTDIR}${PREFIX}/lib/elixir/lib/hex/ebin/

ALL_ENV+=	MIX_ENV="prod"
# FIX THIS: warning: the VM is running with native name encoding of latin1 which may cause Elixir to malfunction as it expects utf8.
# Please ensure your locale is set to UTF-8 (which can be verified by running "locale" in your shell)
ALL_ENV+=	LANG="en_US.UTF-8"
ALL_ENV+=	LC_ALL="en_US.UTF-8"

do-build:
	${RUN} cd ${WRKSRC} && ${SETENV} ${ALL_ENV} ${PREFIX}/bin/mix local.hex --force

do-install:
	${MKDIR} ${EBIN_DIR}
	${INSTALL_DATA} ${WRKDIR}/.home/.mix/archives/${DISTNAME}/${DISTNAME}/ebin/* ${EBIN_DIR}

.include "../../mk/bsd.pkg.mk"
