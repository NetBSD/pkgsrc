# New ports collection makefile for: cddbd
# Version required:                  1.3.1 patch 1
# Date created:                      18 Apr 1997
# Whom:                              Brent J. Nordquist <bjn@visi.com>
#
# $Id: Makefile,v 1.1.1.1 1997/10/28 23:18:25 augustss Exp $
#

DISTNAME=          cddbd-1.3.1
PKGNAME=           cddbd-1.3.1p1
CATEGORIES=        audio net
MASTER_SITES=      ftp://ftp.moonsoft.com/pub/cddbd-1.3.1/ \
                   http://www.moonsoft.com/ftp/cddbd-1.3.1/

PATCH_SITES=       ${MASTER_SITES}
PATCHFILES=        cddbd-1.3.1.patch1.gz

MAINTAINER=        bjn@visi.com

IS_INTERACTIVE=    yes
NO_PACKAGE=        too interactive
MAKEFILE=          makefile

do-configure:
	@( cd ${WRKSRC} && BASEDIR=${PREFIX}/share sh config.sh )

do-install:
	@( cd ${WRKSRC} && INSTALL=${INSTALL} BINDIR=${PREFIX}/bin \
	  BINPERM=${BINMODE} BINOWNER=${BINOWN} BINGROUP=${BINGRP} \
	  sh install.sh )

.include <bsd.port.mk>
