# $NetBSD: Makefile,v 1.6 2005/01/11 03:16:23 dmcmahill Exp $
#

DISTNAME=	geda-examples-${PKGVERSION}
CATEGORIES=	cad

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Examples for gEDA

CONFLICTS+=	gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

pre-install:
	${RM} -f ${WRKSRC}/config.status.overridden

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/geda
	cd ${WRKSRC} && tar -cf - * | \
		(cd ${PREFIX}/share/examples/geda && tar -xf -)
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/examples/geda
	${CHGRP} -R ${SHAREGRP} ${PREFIX}/share/examples/geda

.include "../../mk/bsd.pkg.mk"
