# $NetBSD: Makefile,v 1.3 2021/04/07 13:34:41 triaxx Exp $

DISTNAME=	idna-6.1.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=benoitc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/benoitc/erlang-idna/
COMMENT=	Pure Erlang IDNA implementation following the RFC5891
LICENSE=	mit

BUILD_DEPENDS+=	rebar3-[0-9]*:../../devel/rebar3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

REBAR=		${PREFIX}/bin/rebar3

do-build:
	cd ${WRKSRC} && REBAR_CACHE_DIR=${WRKDIR}/rebar ${REBAR} compile

pre-install:
	${MV} ${WRKSRC}/_build/default/lib/idna/ebin ${WRKSRC}
	${RM} -rf ${WRKSRC}/_build

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
