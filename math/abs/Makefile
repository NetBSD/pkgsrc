# $NetBSD: Makefile,v 1.3 1999/01/30 23:18:52 agc Exp $
#

DISTNAME=	abs-src-0.5
PKGNAME=	abs-0.5
CATEGORIES=	math x11
MASTER_SITES=	http://www.ping.be/bertin/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ping.be/bertin/abs.shtml

DEPENDS+=	xpm-3.4k:../../graphics/xpm

CONFLICTS=	abs-0.4

USE_X11BASE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abs ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
