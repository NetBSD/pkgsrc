# $NetBSD: Makefile,v 1.2 2003/12/24 09:53:48 jmmv Exp $
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

DIST_SUBDIR=	geda
PKGVERSION=	20030901

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/geda
	cd ${WRKSRC} && tar -cf - * | \
		(cd ${PREFIX}/share/examples/geda && tar -xf -)
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/examples/geda
	${CHGRP} -R ${SHAREGRP} ${PREFIX}/share/examples/geda

.include "../../mk/bsd.pkg.mk"
