# $NetBSD: Makefile,v 1.5 2020/01/14 23:05:23 cheusov Exp $

DISTNAME=	bmkdep-20140112
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=trociny/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/trociny/bmkdep
COMMENT=	NetBSD version of mkdep(1)
LICENSE=	2-clause-bsd

GITHUB_TAG=	${DISTNAME}

MAKE_ENV=	BINOWN=${BINOWN} BINGRP=${BINGRP} \
		MANOWN=${MANOWN} MANGRP=${MANGRP} \
		MKHTML=no MKCATPAGES=no
MAKE_FLAGS=	MANDIR=${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
