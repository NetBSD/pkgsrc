# $NetBSD: Makefile,v 1.23 2004/12/06 16:37:47 minskim Exp $

DISTNAME=	xcircuit-3.3.0
CATEGORIES=	cad graphics
MASTER_SITES=	http://bach.ece.jhu.edu/~tim/programs/xcircuit/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://xcircuit.ece.jhu.edu/
COMMENT=	Drawing program for X11 (especially for circuits)

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl
CONFIGURE_ARGS+=--with-tclincls=${BUILDLINK_PREFIX.tcl}/include
CONFIGURE_ARGS+=--with-tcllibs=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=--with-tkincls=${BUILDLINK_PREFIX.tk}/include
CONFIGURE_ARGS+=--with-tklibs=${BUILDLINK_PREFIX.tk}/lib

BUILD_TARGET=	tcl
INSTALL_TARGET=	install-tcl

post-extract:
	${RM} -fr ${WRKSRC}/examples/CVS
	${MV} -f ${WRKSRC}/examples/.xcircuitrc ${WRKSRC}/examples/xcircuitrc
	${TOUCH} ${WRKSRC}/menudep.h

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xcircuit/
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/xcircuit/

.include "../../graphics/xpm/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
