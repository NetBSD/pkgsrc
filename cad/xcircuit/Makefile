# $NetBSD: Makefile,v 1.9 2003/02/26 03:40:54 jschauma Exp $

DISTNAME=	xcircuit-2.2.0
PKGREVISION=	2
CATEGORIES=	cad graphics
MASTER_SITES=	http://bach.ece.jhu.edu/~tim/programs/xcircuit/archive/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://bach.ece.jhu.edu/~tim/programs/xcircuit/
COMMENT=	Drawing program for X11 (especially for circuits)

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_BUILDLINK2=	yes
USE_IMAKE=	yes

post-extract:
	${RM} -fr ${WRKSRC}/examples/CVS
	${MV} -f ${WRKSRC}/examples/.xcircuitrc ${WRKSRC}/examples/xcircuitrc
	${TOUCH} ${WRKSRC}/menudep.h

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xcircuit/
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/xcircuit/

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/ghostscript.mk"

.include "../../mk/bsd.pkg.mk"
