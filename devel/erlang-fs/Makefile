# $NetBSD: Makefile,v 1.6 2023/06/06 12:40:37 riastradh Exp $

DISTNAME=	fs-8.6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=synrc/}
GITHUB_TAG=	73784d45ed0547e730ffb8907f1e0b2378f440a0

HOMEPAGE=	https://synrc.github.io/fs/
COMMENT=	Native Filesystem Listeners
LICENSE=	isc

GITHUB_PROJECT=	fs

TOOL_DEPENDS+=	rebar3-[0-9]*:../../devel/rebar3
REBAR=		${PREFIX}/bin/rebar3

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	macos
.if ${OPSYS} == "Darwin"
PLIST.macos=	yes
.endif

post-extract:
	${RM} -f ${WRKSRC}/priv/inotifywait.exe

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${REBAR} compile

pre-install:
	${MV} ${WRKSRC}/_build/default/lib/fs/ebin ${WRKSRC}
	${RM} -rf ${WRKSRC}/_build

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
