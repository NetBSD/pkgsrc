# $NetBSD: Makefile,v 1.13 2002/05/03 20:51:33 jtb Exp $

DISTNAME=		hdf5-1.4.3
CATEGORIES=		devel
MASTER_SITES=		ftp://hdf.ncsa.uiuc.edu/HDF5/hdf5-1.4.3/src/ \
			ftp://sunsite.doc.ic.ac.uk/packages/HDF/HDF5/hdf5-1.4.3/src/ \
			http://www.go.dlr.de/fresh/unix/src/misc/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://hdf.ncsa.uiuc.edu/HDF5/
COMMENT=		Hierarchical Data Format (new generation)

GNU_CONFIGURE=		# defined
USE_BUILDLINK_ONLY=	# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/bin/ltconfig

CONFIGURE_ENV+=		H5CC_CFLAGS=-I${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ENV+=		H5CC_LDFLAGS="-Wl,-R${BUILDLINK_PREFIX.zlib}/lib -L${BUILDLINK_PREFIX.zlib}/lib"

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/misc/h5cc ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hdf5
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING release_docs/HISTORY.txt \
		release_docs/RELEASE.txt ${PREFIX}/share/doc/hdf5
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/hdf5
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}/doc/html
	cd ${WRKSRC}/doc/html && ${PAX} -rw . ${PREFIX}/share/doc/html/hdf5

.include "../../devel/zlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
