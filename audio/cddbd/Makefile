# $NetBSD: Makefile,v 1.13 2007/12/29 10:13:08 wiz Exp $
#

DISTNAME=	cddbd-1.3.1
PKGNAME=	cddbd-1.3.1p1
PKGREVISION=	1
CATEGORIES=	audio net
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/cddbd-1.3.1/}

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	cddbd-1.3.1.patch1.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedb.org/en/download__server_software.4.html
COMMENT=	Internet CD Database Server

MAKE_FILE=	makefile

do-configure:
	cd ${WRKSRC};							\
	${SETENV} BASEDIR=${PREFIX:Q}/share ${SH} config.sh

do-install:
	cd ${WRKSRC};							\
	${SETENV} INSTALL=${INSTALL:Q} BINDIR=${PREFIX:Q}/bin		\
	  BINPERM=${BINMODE:Q} BINOWNER=${BINOWN:Q}			\
	  BINGROUP=${BINGRP:Q} ${SH} install.sh

.include "../../mk/bsd.pkg.mk"
