# $NetBSD: Makefile,v 1.23 2012/09/11 23:04:16 asau Exp $
#

DISTNAME=	abs-src-0.8
PKGNAME=	abs-0.8
PKGREVISION=	2
CATEGORIES=	math x11
MASTER_SITES=	http://home.scarlet.be/~pin01858/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.scarlet.be/~pin01858/abs.html
COMMENT=	Free spreadsheet with graphical user interface
LICENSE=	gnu-gpl-v2

USE_X11BASE=	YES
MAKE_FILE=	Makefile.netBSD

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abs ${DESTDIR}${PREFIX}/bin

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
