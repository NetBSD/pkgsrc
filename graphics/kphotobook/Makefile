# $NetBSD: Makefile,v 1.2 2004/10/03 00:14:54 tv Exp $
#

DISTNAME=	kphotobook-0.0.6
PKGREVISION=	1
CATEGORIES=	kde graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kphotobook/}

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://kphotobook.sourceforge.net/
COMMENT=	Powerful, intuitive KDE application to manage and organize your photos

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
