# $NetBSD: Makefile,v 1.4 2017/08/01 16:51:55 wiz Exp $

DISTNAME=	bmkdep-20131215
CATEGORIES=	devel
MASTER_SITES=	http://bmkdep.googlecode.com/files/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/bmkdep/
COMMENT=	NetBSD version of mkdep(1)
LICENSE=	2-clause-bsd

MAKE_ENV=	BINOWN=${BINOWN} BINGRP=${BINGRP} \
		MANOWN=${MANOWN} MANGRP=${MANGRP} \
		MKHTML=no MKCATPAGES=no
MAKE_FLAGS=	MANDIR=${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
