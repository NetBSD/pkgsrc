# $NetBSD: Makefile,v 1.29 2005/06/15 01:51:32 dmcmahill Exp $

DISTNAME=	hdf5-1.6.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ncsa.uiuc.edu/HDF/HDF5/hdf5-1.6.4/src/ \
		ftp://sunsite.doc.ic.ac.uk/packages/HDF/HDF5/hdf5-1.6.4/src/ \
		http://www.go.dlr.de/fresh/unix/src/misc/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://hdf.ncsa.uiuc.edu/HDF5/
COMMENT=	Hierarchical Data Format (new generation)

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check

# it appears that this file is informative only and is not actually
# used by any installed tools
CHECK_WRKREF_SKIP=	${PREFIX}/lib/libhdf5.settings

.include "options.mk"

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/misc/h5cc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/misc/h5redeploy.in ${PREFIX}/bin/h5redeploy
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hdf5
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING release_docs/HISTORY.txt \
		release_docs/RELEASE.txt ${PREFIX}/share/doc/hdf5
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/hdf5
	# avoid installing the Makefile and Makefile.in's  They are not needed
	cd ${WRKSRC}/doc/html && ${PAX} -s '/.*Makefile.*//' -rw . ${PREFIX}/share/doc/html/hdf5
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/doc/html/hdf5
	${CHGRP} -R ${SHAREGRP} ${PREFIX}/share/doc/html/hdf5

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
