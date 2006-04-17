# $NetBSD: Makefile,v 1.7 2006/04/17 13:46:33 wiz Exp $
#

DISTNAME=	kphotobook-0.0.6
PKGREVISION=	4
CATEGORIES=	kde graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kphotobook/}

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://kphotobook.sourceforge.net/
COMMENT=	Powerful, intuitive KDE application to manage and organize your photos

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
