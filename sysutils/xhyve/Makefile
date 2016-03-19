# $NetBSD: Makefile,v 1.1 2016/03/19 18:11:36 sevan Exp $

VERSION=	0.2.0
DISTNAME=	xhyve-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=mist64/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	terin@terinstock.com
HOMEPAGE=	https://github.com/mist64/xhyve/
COMMENT=	Port of bhyve to OS X
LICENSE=	2-clause-bsd

MAKE_ENV+=	GIT_VERSION=${PKGVERSION}

ONLY_FOR_PLATFORM+=	Darwin-1[4-9].*-x86_64

AUTO_MKDIRS=	yes
USE_TOOLS+=	gmake

do-install:
	cd ${WRKSRC} && \
	${INSTALL_PROGRAM} build/xhyve ${DESTDIR}${PREFIX}/bin/xhyve

.include "../../mk/bsd.pkg.mk"
