# $NetBSD: Makefile,v 1.1.1.1 2004/08/03 13:16:44 markd Exp $
#

DISTNAME=	krusader-1.40
CATEGORIES=	kde sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=krusader/}

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://krusader.sourceforge.net/
COMMENT=	Advanced twin-panel (commander-style) file-manager for KDE 3.x

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

SHLIBTOOL_OVERRIDE=	libtool

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
