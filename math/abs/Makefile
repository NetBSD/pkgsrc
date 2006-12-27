# $NetBSD: Makefile,v 1.19 2006/12/27 13:37:39 joerg Exp $
#

DISTNAME=	abs-src-0.8
PKGNAME=	abs-0.8
PKGREVISION=	1
CATEGORIES=	math x11
MASTER_SITES=	http://www.ping.be/bertin/

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=	http://www.ping.be/bertin/abs.shtml
# AWOL
COMMENT=	Free spreadsheet with graphical user interface

USE_X11BASE=	YES
MAKE_FILE=	Makefile.netBSD

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abs ${PREFIX}/bin

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
