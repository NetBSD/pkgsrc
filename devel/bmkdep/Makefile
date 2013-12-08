# $NetBSD: Makefile,v 1.1 2013/12/08 15:22:23 cheusov Exp $

DISTNAME=	bmkdep-20131009
CATEGORIES=	devel
MASTER_SITES=	http://bmkdep.googlecode.com/files/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://code.google.com/p/bmkdep/
COMMENT=	NetBSD version of mkdep(1)
LICENSE=	2-clause-bsd

MAKE_ENV=	BINOWN=${BINOWN} BINGRP=${BINGRP} \
		MANOWN=${MANOWN} MANGRP=${MANGRP} \
		MKHTML=no MKCATPAGES=no
MAKE_FLAGS=	MANDIR=${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
