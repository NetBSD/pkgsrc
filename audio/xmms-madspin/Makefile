# $NetBSD: Makefile,v 1.8 2004/02/14 17:21:34 jlam Exp $
#

DISTNAME=	madspin-0.05
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	xmms audio
MASTER_SITES=	http://www.students.uiuc.edu/~birck/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.students.uiuc.edu/~birck/madspin.html
COMMENT=	Based on the madspin winamp plugin

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

.include "../../audio/xmms/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
