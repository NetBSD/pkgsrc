# $NetBSD: Makefile,v 1.12 2004/01/22 14:00:01 jlam Exp $

DISTNAME=	cxunzip-0.98
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://gurb.ton.tut.fi/gnome/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gurb.ton.tut.fi/gnome
COMMENT=	Cloned Xunzip is a GNOME zip-archive uncompressing program

USE_BUILDLINK3=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
#USE_LIBTOOL=	yes

.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
