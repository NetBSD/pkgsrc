# $NetBSD: Makefile,v 1.2 2004/10/03 00:14:58 tv Exp $
#

DISTNAME=	showimg-0.9.3
PKGREVISION=	1
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
