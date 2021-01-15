# $NetBSD: Makefile,v 1.1 2021/01/15 23:20:36 triaxx Exp $

DISTNAME=	idna-6.1.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=benoitc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/benoitc/erlang-idna/
COMMENT=	Pure Erlang IDNA implementation following the RFC5891
LICENSE=	mit

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

REBAR=		${PREFIX}/bin/rebar3

do-build:
	cd ${WRKSRC} && ${REBAR} compile

pre-install:
	${MV} ${WRKSRC}/_build/default/lib/idna/ebin ${WRKSRC}
	${RM} -rf ${WRKSRC}/_build

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
