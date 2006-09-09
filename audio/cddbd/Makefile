# $NetBSD: Makefile,v 1.9 2006/09/09 02:41:54 obache Exp $
#

DISTNAME=	cddbd-1.3.1
PKGNAME=	cddbd-1.3.1p1
CATEGORIES=	audio net
MASTER_SITES=	ftp://ftp.moonsoft.com/pub/cddbd-1.3.1/ \
		http://www.moonsoft.com/ftp/cddbd-1.3.1/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	cddbd-1.3.1.patch1.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.moonsoft.com/software.html
COMMENT=	Internet CD Database Server

INTERACTIVE_STAGE=	configure install
NO_PACKAGE=	too interactive
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
