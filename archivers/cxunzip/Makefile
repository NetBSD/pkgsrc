# $NetBSD: Makefile,v 1.10 2004/01/03 18:49:33 reed Exp $

DISTNAME=	cxunzip-0.98
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://gurb.ton.tut.fi/gnome/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gurb.ton.tut.fi/gnome
COMMENT=	Cloned Xunzip is a GNOME zip-archive uncompressing program

USE_BUILDLINK2=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
#USE_LIBTOOL=	yes

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
