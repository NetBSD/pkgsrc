# $NetBSD: Makefile,v 1.8 2002/10/21 12:31:19 wiz Exp $
#

DISTNAME=	abs-src-0.8
PKGNAME=	abs-0.8
CATEGORIES=	math x11
MASTER_SITES=	http://www.ping.be/bertin/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ping.be/bertin/abs.shtml
COMMENT=	Free spreadsheet with graphical user interface

USE_BUILDLINK2=	YES
USE_X11BASE=	YES
MAKEFILE=	Makefile.netBSD

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abs ${PREFIX}/bin

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
