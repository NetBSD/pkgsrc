# $NetBSD: Makefile,v 1.1.1.1 1998/12/05 12:33:18 frueauf Exp $
#

DISTNAME=	abs-src-0.4
PKGNAME=	abs-0.4
CATEGORIES=	math x11
MASTER_SITES=	http://www.ping.be/bertin/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ping.be/bertin/abs.shtml

DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_X11=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abs ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
