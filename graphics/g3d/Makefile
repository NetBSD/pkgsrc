# $NetBSD: Makefile,v 1.4 2001/02/16 15:22:20 wiz Exp $
#

DISTNAME=	g3d-0.0.2
CATEGORIES=	graphics
MASTER_SITES=	http://condor.stcloudstate.edu/~hebl9901/g3d/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://condor.stcloudstate.edu/~hebl9901/g3d/
COMMENT=	3D modeller with a view of 3D modelling

DEPENDS+=	gtkglarea-1.2.1:../../x11/gtkglarea

WRKSRC=		${WRKDIR}/g3d

USE_LIBTOOL=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES
GNU_CONFIGURE=	YES

post-configure:
	@${LN} -s ${WRKSRC}/b3d/src ${WRKSRC}/g3d/b3d

.include "../../mk/bsd.pkg.mk"
