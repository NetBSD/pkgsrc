# $NetBSD: Makefile,v 1.5 2000/08/23 23:14:29 tron Exp $
#

DISTNAME=	abs-src-0.5
PKGNAME=	abs-0.5
CATEGORIES=	math x11
MASTER_SITES=	http://www.ping.be/bertin/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ping.be/bertin/abs.shtml

USE_X11BASE=	YES
USE_XPM=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abs ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
