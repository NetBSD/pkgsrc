# $NetBSD: Makefile,v 1.7 2005/03/24 02:05:11 dmcmahill Exp $
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
	${RM} -f ${WRKSRC}/configure.lineno

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/geda
	cd ${WRKSRC} && ${TAR} -cf - * | \
		(cd ${PREFIX}/share/examples/geda && ${TAR} -xf -)
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/examples/geda
	${CHGRP} -R ${SHAREGRP} ${PREFIX}/share/examples/geda

.include "../../mk/bsd.pkg.mk"
