# $NetBSD: Makefile,v 1.5 2001/02/25 00:05:39 jtb Exp $

DISTNAME=		hdf5-1.4.0
CATEGORIES=		devel
MASTER_SITES=		ftp://hdf.ncsa.uiuc.edu/HDF5/hdf5-1.2.2/src/ \
			ftp://sunsite.doc.ic.ac.uk/packages/HDF5/hdf5-1.2.2/src/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://hdf.ncsa.uiuc.edu/HDF5/
COMMENT=		Hierarchical Data Format (version 5)

DEPENDS+=		jpeg>=6:../../graphics/jpeg

GNU_CONFIGURE=		#defined
USE_LIBTOOL=		#defined
LTCONFIG_OVERRIDE= 	${WRKSRC}/bin/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hdf5
	${INSTALL_DATA} ${WRKSRC}/COPYING ${WRKSRC}/README	\
	${WRKSRC}/RELEASE.txt ${PREFIX}/share/doc/hdf5
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/hdf5
	(cd ${WRKSRC}/doc/html; ${GTAR} cf - . ) |		\
	(cd ${PREFIX}/share/doc/html/hdf5/; ${GTAR} xf - )

.include "../../mk/bsd.pkg.mk"
