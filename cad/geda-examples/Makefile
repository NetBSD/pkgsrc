# $NetBSD: Makefile,v 1.4 2004/02/23 04:02:55 dmcmahill Exp $
#

DISTNAME=	geda-examples-${PKGVERSION}
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
		ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
		http://www.geda.seul.org/devel/${PKGVERSION}/ \
		http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Examples for gEDA

CONFLICTS+=	gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/geda
	cd ${WRKSRC} && tar -cf - * | \
		(cd ${PREFIX}/share/examples/geda && tar -xf -)
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/examples/geda
	${CHGRP} -R ${SHAREGRP} ${PREFIX}/share/examples/geda

.include "../../mk/bsd.pkg.mk"
