# $NetBSD: Makefile,v 1.15 2004/10/03 00:13:04 tv Exp $

DISTNAME=	cxunzip-0.98
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	http://gurb.ton.tut.fi/gnome/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gurb.ton.tut.fi/gnome
COMMENT=	Cloned Xunzip is a GNOME zip-archive uncompressing program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make

.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
