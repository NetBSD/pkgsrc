# $NetBSD: Makefile,v 1.7 2001/03/04 18:05:23 jtb Exp $

DISTNAME=		hdf5-1.4.0
CATEGORIES=		devel
MASTER_SITES=		ftp://hdf.ncsa.uiuc.edu/HDF5/hdf5-1.4.0/src/ \
			ftp://sunsite.doc.ic.ac.uk/packages/HDF/HDF5/hdf5-1.4.0/src/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://hdf.ncsa.uiuc.edu/HDF5/
COMMENT=		Hierarchical Data Format (version 5)

DEPENDS+=		jpeg>=6:../../graphics/jpeg

GNU_CONFIGURE=		#defined
USE_LIBTOOL=		#defined
LTCONFIG_OVERRIDE=	${WRKSRC}/bin/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hdf5
	${INSTALL_DATA} ${WRKSRC}/COPYING ${WRKSRC}/README	\
	${WRKSRC}/RELEASE.txt ${PREFIX}/share/doc/hdf5
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/hdf5
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}/doc/html/
	(cd ${WRKSRC}/doc/html; ${GTAR} cf - . ) |		\
	(cd ${PREFIX}/share/doc/html/hdf5/; ${GTAR} xf - )

.include "../../mk/bsd.pkg.mk"
