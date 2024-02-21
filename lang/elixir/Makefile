# $NetBSD: Makefile,v 1.40 2024/02/21 10:29:44 wiz Exp $

DISTNAME=	elixir-1.16.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=elixir-lang/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://elixir-lang.org/
COMMENT=	Functional, meta-programming aware language built on top of Erlang VM
LICENSE=	apache-2.0

DEPENDS+=	erlang>=23.0:../../lang/erlang

UNLIMIT_RESOURCES=	datasize virtualsize

USE_TOOLS+=	gmake:run
BUILD_TARGET=	compile
TEST_TARGET=	test

# https://github.com/elixir-lang/elixir/issues/12320
MAKE_JOBS_SAFE=	no

MAKE_FLAGS+=	MAN_PREFIX=${PREFIX}/${PKGMANDIR}

REPLACE_INTERPRETER+=	elixir
REPLACE.elixir.old=	.*elixir
REPLACE.elixir.new=	${TOOLS_PLATFORM.env:Q} ${PREFIX}/bin/elixir
REPLACE_FILES.elixir=	bin/mix

CHECK_INTERPRETER_SKIP+=	bin/mix
CHECK_INTERPRETER_SKIP+=	lib/elixir/bin/mix

# Debug locale problems.
pre-build:
	@${ECHO} ENV:
	@${PKGSRC_SETENV} ${MAKE_ENV} env | egrep "^(LANG|LC_)" || ${TRUE}
	@${ECHO} LOCALE:
	@${PKGSRC_SETENV} ${MAKE_ENV} locale

.include "../../mk/bsd.pkg.mk"

# erlang chooses latin1 or utf8 encoding for file names depending on
# the character encoding, and elixir requires utf8.  Force erl to
# choose utf8.  We'd like to set LC_CTYPE, but we need to override the
# LC_ALL set by bsd.pkg.mk.
ALL_ENV+=	LC_ALL="en_US.UTF-8"
