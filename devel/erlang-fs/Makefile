# $NetBSD: Makefile,v 1.7 2024/07/14 06:11:40 wiz Exp $

DISTNAME=	fs-8.6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=synrc/}
GITHUB_PROJECT=	fs
GITHUB_TAG=	73784d45ed0547e730ffb8907f1e0b2378f440a0

HOMEPAGE=	https://synrc.github.io/fs/
COMMENT=	Native Filesystem Listeners
LICENSE=	isc

TOOL_DEPENDS+=	rebar3-[0-9]*:../../devel/rebar3

# XXX: this package should be fixed to not require network access during build
ALLOW_NETWORK_ACCESS=	1

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
