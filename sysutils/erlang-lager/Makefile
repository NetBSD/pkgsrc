# $NetBSD: Makefile,v 1.7 2021/01/16 00:10:50 triaxx Exp $

DISTNAME=	lager-3.8.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=erlang-lager/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/erlang-lager/lager/
COMMENT=	Logging framework for Erlang/OTP
LICENSE=	apache-2.0

BUILD_DEPENDS+=	rebar3-[0-9]*:../../devel/rebar3
DEPENDS+=	erlang-goldrush>=0.1.9:../../sysutils/erlang-goldrush

GITHUB_PROJECT=	lager
GITHUB_TAG=	${PKGVERSION_NOREV}

REBAR=		${PREFIX}/bin/rebar3

SUBST_CLASSES+=		rebar
SUBST_STAGE.rebar=	pre-configure
SUBST_MESSAGE.rebar=	Using rebar3 to compile.
SUBST_FILES.rebar=	Makefile
SUBST_VARS.rebar=	REBAR

post-extract:
	# Remove dependency handling
	${RM} -f ${WRKSRC}/rebar.config.script

pre-install:
	# Move rebar3 build tree to make working the do-install rule of module.mk
	${MV} ${WRKSRC}/_build/default/lib/lager/ebin ${WRKSRC}
	${RM} -rf ${WRKSRC}/_build

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
