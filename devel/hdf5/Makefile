# $NetBSD: Makefile,v 1.25 2005/02/25 09:10:18 adam Exp $

DISTNAME=	hdf5-1.6.3
CATEGORIES=	devel
MASTER_SITES=	ftp://hdf.ncsa.uiuc.edu/HDF5/hdf5-1.6.3/src/ \
		ftp://sunsite.doc.ic.ac.uk/packages/HDF/HDF5/hdf5-1.6.3/src/ \
		http://www.go.dlr.de/fresh/unix/src/misc/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://hdf.ncsa.uiuc.edu/HDF5/
COMMENT=	Hierarchical Data Format (new generation)

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-szlib
TEST_TARGET=		check

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/misc/h5cc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/misc/h5redeploy.in ${PREFIX}/bin/h5redeploy
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hdf5
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING release_docs/HISTORY.txt \
		release_docs/RELEASE.txt ${PREFIX}/share/doc/hdf5
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/hdf5
	cd ${WRKSRC}/doc/html && ${PAX} -rw . ${PREFIX}/share/doc/html/hdf5
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/html/hdf5

.include "../../archivers/szip/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
