# $NetBSD: Makefile,v 1.6 2000/11/17 07:36:33 rh Exp $
#

DISTNAME=	abs-src-0.8
PKGNAME=	abs-0.8
CATEGORIES=	math x11
MASTER_SITES=	http://www.ping.be/bertin/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ping.be/bertin/abs.shtml

USE_XPM=	YES
USE_X11BASE=	YES
MAKEFILE=	Makefile.netBSD

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abs ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
