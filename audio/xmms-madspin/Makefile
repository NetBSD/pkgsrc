# $NetBSD: Makefile,v 1.7 2004/01/22 07:15:01 grant Exp $
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
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

.include "../../audio/xmms/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
