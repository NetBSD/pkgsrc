# $NetBSD: Makefile,v 1.6 2002/07/02 11:27:44 agc Exp $
#

DISTNAME=	cddbd-1.3.1
PKGNAME=	cddbd-1.3.1p1
CATEGORIES=	audio net
MASTER_SITES=	ftp://ftp.moonsoft.com/pub/cddbd-1.3.1/ \
		http://www.moonsoft.com/ftp/cddbd-1.3.1/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	cddbd-1.3.1.patch1.gz

MAINTAINER=	bjn@visi.com
HOMEPAGE=	http://www.moonsoft.com/software.html
COMMENT=	Internet CD Database Server

INTERACTIVE_STAGE=	configure install
NO_PACKAGE=	too interactive
MAKEFILE=	makefile

do-configure:
	@( cd ${WRKSRC} && BASEDIR=${PREFIX}/share sh config.sh )

do-install:
	@( cd ${WRKSRC} && INSTALL=${INSTALL} BINDIR=${PREFIX}/bin \
	  BINPERM=${BINMODE} BINOWNER=${BINOWN} BINGROUP=${BINGRP} \
	  sh install.sh )

.include "../../mk/bsd.pkg.mk"
