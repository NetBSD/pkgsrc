# $NetBSD: Makefile,v 1.15 2004/03/08 19:40:39 jmmv Exp $
#

DISTNAME=	g3d-0.0.2
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://condor.stcloudstate.edu/~hebl9901/g3d/

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://condor.stcloudstate.edu/~hebl9901/g3d/
COMMENT=	3D modeller with a view of 3D modelling

DEPENDS+=	xdg-x11-dirs>=1.1:../../misc/xdg-x11-dirs

WRKSRC=		${WRKDIR}/g3d
USE_LIBTOOL=	YES
USE_GNU_TOOLS+=	make
USE_X11BASE=	YES
GNU_CONFIGURE=	YES
USE_BUILDLINK2=	yes

post-configure:
	@${LN} -s ${WRKSRC}/b3d/src ${WRKSRC}/g3d/b3d

.include "../../graphics/glu/buildlink2.mk"
.include "../../x11/gtkglarea/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
