# $NetBSD: Makefile,v 1.15 2002/10/28 16:32:01 drochner Exp $

DISTNAME=		hdf5-1.4.4
CATEGORIES=		devel
MASTER_SITES=		ftp://hdf.ncsa.uiuc.edu/HDF5/hdf5-1.4.4/src/ \
			ftp://sunsite.doc.ic.ac.uk/packages/HDF/HDF5/hdf5-1.4.4/src/ \
			http://www.go.dlr.de/fresh/unix/src/misc/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://hdf.ncsa.uiuc.edu/HDF5/
COMMENT=		Hierarchical Data Format (new generation)

GNU_CONFIGURE=		# defined
USE_BUILDLINK2=		# defined
USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/misc/h5cc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/misc/h5redeploy.in ${PREFIX}/bin/h5redeploy
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hdf5
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING release_docs/HISTORY.txt \
		release_docs/RELEASE.txt ${PREFIX}/share/doc/hdf5
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/hdf5
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}/doc/html
	cd ${WRKSRC}/doc/html && ${PAX} -rw . ${PREFIX}/share/doc/html/hdf5

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
