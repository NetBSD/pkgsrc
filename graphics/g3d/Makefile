# $NetBSD: Makefile,v 1.7 2002/12/08 02:44:13 salo Exp $
#

DISTNAME=	g3d-0.0.2
CATEGORIES=	graphics
MASTER_SITES=	http://condor.stcloudstate.edu/~hebl9901/g3d/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://condor.stcloudstate.edu/~hebl9901/g3d/
COMMENT=	3D modeller with a view of 3D modelling

WRKSRC=		${WRKDIR}/g3d

USE_LIBTOOL=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES
GNU_CONFIGURE=	YES

USE_BUILDLINK2=	yes

post-configure:
	@${LN} -s ${WRKSRC}/b3d/src ${WRKSRC}/g3d/b3d

.include "../../graphics/glu/buildlink2.mk"
.include "../../x11/gtkglarea/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
