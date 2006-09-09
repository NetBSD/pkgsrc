# $NetBSD: Makefile,v 1.16 2006/09/09 02:43:10 obache Exp $
#

DISTNAME=	abs-src-0.8
PKGNAME=	abs-0.8
PKGREVISION=	1
CATEGORIES=	math x11
MASTER_SITES=	http://www.ping.be/bertin/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ping.be/bertin/abs.shtml
COMMENT=	Free spreadsheet with graphical user interface

USE_X11BASE=	YES
MAKE_FILE=	Makefile.netBSD

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abs ${PREFIX}/bin

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
