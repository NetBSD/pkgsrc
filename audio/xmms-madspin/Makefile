# $NetBSD: Makefile,v 1.4 2003/05/05 19:05:08 jmmv Exp $
#

DISTNAME=	madspin-0.05
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	xmms audio
MASTER_SITES=	http://www.students.uiuc.edu/~birck/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.students.uiuc.edu/~birck/madspin.html
COMMENT=	Based on the madspin winamp plugin

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES
USE_GMAKE=	yes

.include "../../audio/xmms/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
