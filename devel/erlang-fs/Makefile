# $NetBSD: Makefile,v 1.1 2017/12/14 20:58:26 fhajny Exp $

DISTNAME=	fs-2.12.0
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=synrc/}

HOMEPAGE=	http://synrc.github.io/fs/
COMMENT=	Native Filesystem Listeners
LICENSE=	isc

GITHUB_PROJECT=	fs

post-extract:
	${RM} -f ${WRKSRC}/priv/inotifywait.exe

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${REBAR} compile

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
