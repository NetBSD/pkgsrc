# $NetBSD: Makefile,v 1.4 2022/10/15 17:42:05 triaxx Exp $

DISTNAME=	fs-6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=synrc/}

HOMEPAGE=	https://synrc.github.io/fs/
COMMENT=	Native Filesystem Listeners
LICENSE=	isc

GITHUB_PROJECT=	fs

BUILD_DEPENDS+=	rebar3-[0-9]*:../../devel/rebar3
REBAR=		${PREFIX}/bin/rebar3

post-extract:
	${RM} -f ${WRKSRC}/priv/inotifywait.exe

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${REBAR} compile

pre-install:
	${MV} ${WRKSRC}/_build/default/lib/fs/ebin ${WRKSRC}
	${RM} -rf ${WRKSRC}/_build

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
