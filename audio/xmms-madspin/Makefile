# $NetBSD: Makefile,v 1.18 2009/07/08 14:38:35 joerg Exp $
#

DISTNAME=	madspin-0.05
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	xmms audio
MASTER_SITES=	# http://www.students.uiuc.edu/~birck/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.students.uiuc.edu/~birck/madspin.html
COMMENT=	Based on the madspin winamp plugin

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
USE_LIBTOOL=	YES

INSTALLATION_DIRS=	lib/xmms/Visualization share/xmms/madspin

post-install:
	${INSTALL_DATA} ${WRKSRC}/star1.bmp ${DESTDIR}${PREFIX}/share/xmms/madspin
	${INSTALL_DATA} ${WRKSRC}/star2.bmp ${DESTDIR}${PREFIX}/share/xmms/madspin

.include "../../audio/xmms/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
