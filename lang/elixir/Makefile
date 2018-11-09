# $NetBSD: Makefile,v 1.10 2018/11/09 17:17:28 nia Exp $

DISTNAME=		elixir-1.7.4
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GITHUB:=elixir-lang/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://elixir-lang.org/
COMMENT=		Functional, meta-programming aware language built on top of Erlang VM
LICENSE=		apache-2.0

DEPENDS+=		erlang>=18.0:../../lang/erlang

USE_TOOLS+=		gmake

REPLACE_INTERPRETER+=	elixir
REPLACE.elixir.old=	.*elixir
REPLACE.elixir.new=	${PREFIX}/bin/elixir
REPLACE_FILES.elixir=	bin/mix

BUILD_TARGET=		compile
TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
