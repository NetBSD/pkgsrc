# $NetBSD: Makefile,v 1.1.1.1 2004/07/28 13:37:52 markd Exp $
#

DISTNAME=	showimg-0.9.3
CATEGORIES=	kde graphics x11
MASTER_SITES=	http://www.jalix.org/projects/showimg/download/0.9.3/

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://www.jalix.org/projects/showimg/
COMMENT=	Feature-rich image viewer for KDE including an image management system

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_LANGUAGE=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
