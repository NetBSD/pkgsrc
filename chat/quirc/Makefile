# $NetBSD: Makefile,v 1.3 2004/01/22 07:49:21 grant Exp $
#

DISTNAME=	quirc-0.9.82
CATEGORIES=	chat
MASTER_SITES=	http://quirc.org/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://quirc.org/
COMMENT=	Stable and powerful graphical IRC client

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
