# $NetBSD: Makefile,v 1.2 2018/01/03 20:46:55 fhajny Exp $

DISTNAME=	fs-2.12.0
PKGNAME=	erlang-${DISTNAME}
PKGREVISION=	1
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
