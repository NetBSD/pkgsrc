# $NetBSD: Makefile,v 1.3 2010/06/13 22:44:55 wiz Exp $
#

DISTNAME=	extcalc-0.9.3-1
PKGNAME=	extcalc-0.9.3
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=extcalc-linux/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://extcalc-linux.sourceforge.net/
COMMENT=	Scientific graphic calculator

USE_LANGUAGES=	c c++
USE_DIRS+=	xdg-1.1
PKG_DESTDIR_SUPPORT= user-destdir
USE_CMAKE=	yes

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
