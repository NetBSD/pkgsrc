# $NetBSD: Makefile,v 1.5 2003/05/02 11:53:34 wiz Exp $

DISTNAME=	cxunzip-0.96
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	http://gurb.ton.tut.fi/gnome/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gurb.ton.tut.fi/gnome
COMMENT=	Cloned Xunzip is a GNOME zip-archive uncompressing program

USE_BUILDLINK2=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
#USE_LIBTOOL=	yes

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
