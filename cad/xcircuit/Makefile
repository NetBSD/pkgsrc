# $NetBSD: Makefile,v 1.2 2001/01/19 23:24:33 jtb Exp $

DISTNAME=	xcircuit-2.2.0
CATEGORIES=	cad graphics
MASTER_SITES=	http://bach.ece.jhu.edu/~tim/programs/xcircuit/archive/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://bach.ece.jhu.edu/~tim/programs/xcircuit/

DEPENDS+=	ghostscript-[0-9]*:../../print/ghostscript

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_IMAKE=	yes
USE_X11BASE=	yes
USE_XPM=	yes
EVAL_PREFIX+=	GS_PREFIX=ghostscript

post-extract:
	${RM} -fr ${WRKSRC}/examples/CVS
	${MV} -f ${WRKSRC}/examples/.xcircuitrc ${WRKSRC}/examples/xcircuitrc
	${TOUCH} ${WRKSRC}/menudep.h

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xcircuit/
	@for f in ${WRKSRC}/examples/*; do \
		c="${INSTALL_DATA} $$f ${PREFIX}/share/examples/xcircuit/"; \
		${ECHO} $$c; $$c; \
	done

.include "../../mk/bsd.pkg.mk"
