# $NetBSD: Makefile,v 1.4 1998/08/20 15:16:39 tsarna Exp $
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

IS_INTERACTIVE=	yes
NO_PACKAGE=	too interactive
MAKEFILE=	makefile

do-configure:
	@( cd ${WRKSRC} && BASEDIR=${PREFIX}/share sh config.sh )

do-install:
	@( cd ${WRKSRC} && INSTALL=${INSTALL} BINDIR=${PREFIX}/bin \
	  BINPERM=${BINMODE} BINOWNER=${BINOWN} BINGROUP=${BINGRP} \
	  sh install.sh )

.include "../../mk/bsd.pkg.mk"
