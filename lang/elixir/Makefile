# $NetBSD: Makefile,v 1.13 2019/08/01 09:52:52 nia Exp $

DISTNAME=		elixir-1.9.1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GITHUB:=elixir-lang/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://elixir-lang.org/
COMMENT=		Functional, meta-programming aware language built on top of Erlang VM
LICENSE=		apache-2.0

DEPENDS+=		erlang>=20.0:../../lang/erlang

USE_TOOLS+=		gmake

MAKE_FLAGS+=		MAN_PREFIX=${PREFIX}/${PKGMANDIR}

REPLACE_INTERPRETER+=	elixir
REPLACE.elixir.old=	.*elixir
REPLACE.elixir.new=	${TOOLS_PLATFORM.env:Q} ${PREFIX}/bin/elixir
REPLACE_FILES.elixir=	bin/mix

CHECK_INTERPRETER_SKIP+=	bin/mix
CHECK_INTERPRETER_SKIP+=	lib/elixir/bin/mix

BUILD_TARGET=		compile
TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
