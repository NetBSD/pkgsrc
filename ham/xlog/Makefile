# $NetBSD: Makefile,v 1.10 2004/10/03 00:14:59 tv Exp $
#

DISTNAME=	xlog-0.9.3
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	http://www.qsl.net/pg4i/download/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.qsl.net/pg4i/linux/xlog.html
COMMENT=	Amateur Radio logging program

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_PKGLOCALDIR=yes
USE_GNU_TOOLS+=	make

CONFIGURE_ARGS=	--enable-hamlib

.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
