# $NetBSD: Makefile,v 1.10 2004/10/03 00:13:11 tv Exp $
#

DISTNAME=	madspin-0.05
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	xmms audio
MASTER_SITES=	http://www.students.uiuc.edu/~birck/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.students.uiuc.edu/~birck/madspin.html
COMMENT=	Based on the madspin winamp plugin

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xmms/madspin
	${INSTALL_DATA} ${WRKSRC}/star1.bmp ${PREFIX}/share/xmms/madspin
	${INSTALL_DATA} ${WRKSRC}/star2.bmp ${PREFIX}/share/xmms/madspin

.include "../../audio/xmms/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
