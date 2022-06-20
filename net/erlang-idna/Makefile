# $NetBSD: Makefile,v 1.8 2022/06/20 08:00:34 nikita Exp $

DISTNAME=	idna-6.1.1
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=benoitc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/benoitc/erlang-idna/
COMMENT=	Pure Erlang IDNA implementation following the RFC5891
LICENSE=	mit

REBAR3_BUILD=	yes
BUILD_DEPENDS+=	rebar3-[0-9]*:../../devel/rebar3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

REBAR=		${PREFIX}/bin/rebar3

do-build:
	cd ${WRKSRC} && REBAR_CACHE_DIR=${WRKDIR}/rebar ${REBAR} compile

pre-install:
	${MV} ${WRKSRC}/_build/default/lib/idna/ebin ${WRKSRC}
	# Apparently this package depends on unicode_util_compat, but
	# doesn't say that in the README.md, and includes (by
	# downloading from the net at build time) a version.  Rather
	# than fixing this, wait until the next release which will no
	# longer have this problem.
	# https://github.com/benoitc/erlang-idna/issues/39
	${MV} ${WRKSRC}/_build/default/lib/unicode_util_compat/ebin/* ${WRKSRC}/ebin
	${RM} -rf ${WRKSRC}/_build

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
