# $NetBSD: Makefile,v 1.1.1.1 1999/07/22 03:35:20 sakamoto Exp $
#

DISTNAME=	g3d-0.0.2
CATEGORIES=	graphics
MASTER_SITES=	http://condor.stcloudstate.edu/~hebl9901/g3d/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://condor.stcloudstate.edu/~hebl9901/g3d/

DEPENDS+=	gtkglarea-1.2.1:../../x11/gtkglarea

WRKSRC=		${WRKDIR}/g3d

USE_LIBTOOL=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES
GNU_CONFIGURE=	YES

post-configure:
	@${LN} -s ${WRKSRC}/b3d/src ${WRKSRC}/g3d/b3d

.include "../../mk/bsd.pkg.mk"
