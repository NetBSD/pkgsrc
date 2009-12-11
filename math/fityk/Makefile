# $NetBSD: Makefile,v 1.1.1.1 2009/12/11 20:44:38 drochner Exp $
#

DISTNAME=	fityk-0.8.9
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fityk/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fityk.sourceforge.net/
COMMENT=	Peak fitting software
#LICENSE=	LICENSE

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_DIRS+=	xdg-1.1
PKG_DESTDIR_SUPPORT= user-destdir

.include "../../math/xylib/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
