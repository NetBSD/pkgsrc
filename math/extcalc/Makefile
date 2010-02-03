# $NetBSD: Makefile,v 1.1.1.1 2010/02/03 14:05:01 drochner Exp $
#

DISTNAME=	extcalc-0.9.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=extcalc-linux/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://extcalc-linux.sourceforge.net/
COMMENT=	Scientific graphic calculator

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_DIRS+=	xdg-1.1
PKG_DESTDIR_SUPPORT= user-destdir

SUBST_CLASSES+=	iconpath
SUBST_STAGE.iconpath=	pre-configure
SUBST_FILES.iconpath=	share/extcalc.desktop
SUBST_VARS.iconpath=	PREFIX

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
