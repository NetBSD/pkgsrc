# $NetBSD: Makefile,v 1.3 2020/01/18 23:30:27 rillig Exp $

DISTNAME=	fs-2.12.0
PKGNAME=	erlang-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=synrc/}

HOMEPAGE=	https://synrc.github.io/fs/
COMMENT=	Native Filesystem Listeners
LICENSE=	isc

GITHUB_PROJECT=	fs

post-extract:
	${RM} -f ${WRKSRC}/priv/inotifywait.exe

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${REBAR} compile

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
