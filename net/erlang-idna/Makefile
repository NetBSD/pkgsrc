# $NetBSD: Makefile,v 1.12 2026/08/06 00:30:38 gdt Exp $

DISTNAME=	idna-7.1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=benoitc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/benoitc/erlang-idna/
COMMENT=	Pure Erlang IDNA implementation following the RFC5891
LICENSE=	mit

# It is mysterious why this package does not build in a normal manner
# and lacks build instructions.

# TODO: this downloads files during build

REBAR3_BUILD=	yes
TOOL_DEPENDS+=	rebar3-[0-9]*:../../devel/rebar3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

REBAR=		${PREFIX}/bin/rebar3

do-build:
	cd ${WRKSRC} && REBAR_CACHE_DIR=${WRKDIR}/rebar ${REBAR} compile

pre-install:
	${MV} ${WRKSRC}/_build/default/lib/idna/ebin ${WRKSRC}
	${RM} -rf ${WRKSRC}/_build

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
