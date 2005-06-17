# $NetBSD: Makefile,v 1.13 2005/06/17 03:50:19 jlam Exp $
#

DISTNAME=	abs-src-0.8
PKGNAME=	abs-0.8
CATEGORIES=	math x11
MASTER_SITES=	http://www.ping.be/bertin/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ping.be/bertin/abs.shtml
COMMENT=	Free spreadsheet with graphical user interface

USE_X11BASE=	YES
MAKEFILE=	Makefile.netBSD

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abs ${PREFIX}/bin

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
