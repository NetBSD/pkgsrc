# $NetBSD: Makefile,v 1.16 2007/01/11 11:51:12 joerg Exp $
#

DISTNAME=	madspin-0.05
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	xmms audio
MASTER_SITES=	http://www.students.uiuc.edu/~birck/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.students.uiuc.edu/~birck/madspin.html
COMMENT=	Based on the madspin winamp plugin

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
USE_LIBTOOL=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xmms/madspin
	${INSTALL_DATA} ${WRKSRC}/star1.bmp ${PREFIX}/share/xmms/madspin
	${INSTALL_DATA} ${WRKSRC}/star2.bmp ${PREFIX}/share/xmms/madspin

.include "../../audio/xmms/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
