# $NetBSD: Makefile,v 1.4 1999/02/20 22:48:35 hubertf Exp $
#

DISTNAME=	abs-src-0.5
PKGNAME=	abs-0.5
CATEGORIES=	math x11
MASTER_SITES=	http://www.ping.be/bertin/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ping.be/bertin/abs.shtml

DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_X11BASE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abs ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
