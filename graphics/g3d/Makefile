# $NetBSD: Makefile,v 1.21 2005/05/22 20:08:05 jlam Exp $
#

DISTNAME=	g3d-0.0.2
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://condor.stcloudstate.edu/~hebl9901/g3d/

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://condor.stcloudstate.edu/~hebl9901/g3d/
COMMENT=	3D modeller with a view of 3D modelling

WRKSRC=		${WRKDIR}/g3d
USE_DIRS+=	xdg-1.1
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake
USE_X11BASE=	YES
GNU_CONFIGURE=	YES

post-configure:
	@${LN} -s ${WRKSRC}/b3d/src ${WRKSRC}/g3d/b3d

.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtkglarea/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
