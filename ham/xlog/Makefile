# $NetBSD: Makefile,v 1.6 2004/03/04 22:28:38 wulf Exp $
#

DISTNAME=	xlog-0.9.1
CATEGORIES=	ham
MASTER_SITES=	http://www.qsl.net/pg4i/download/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.qsl.net/pg4i/linux/xlog.html
COMMENT=	Amateur Radio logging program

USE_BUILDLINK2=	yes
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-hamlib

.include "../../ham/hamlib/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
