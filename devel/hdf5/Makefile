# $NetBSD: Makefile,v 1.40 2008/05/26 02:13:17 joerg Exp $

DISTNAME=	hdf5-1.6.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.hdfgroup.org/HDF5/current/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hdf.ncsa.uiuc.edu/HDF5/
COMMENT=	Hierarchical Data Format (new generation)

DIST_SUBDIR=		${PKGNAME_NOREV}
USE_LIBTOOL=		yes
USE_TOOLS+=		pax tr
GNU_CONFIGURE=		yes
TEST_TARGET=		check
#CONFIGURE_ARGS+= --disable-production --enable-debug

# it appears that this file is informative only and is not actually
# used by any installed tools
CHECK_WRKREF_SKIP=	${PREFIX}/lib/libhdf5.settings

.include "options.mk"

INSTALL_ENV+=	INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}

post-extract:
	${CP} ${WRKSRC}/config/freebsd ${WRKSRC}/config/netbsd
	${CP} ${WRKSRC}/config/freebsd ${WRKSRC}/config/netbsdelf

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/misc/h5cc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/misc/h5redeploy.in ${PREFIX}/bin/h5redeploy
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hdf5
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING release_docs/HISTORY.txt \
		release_docs/RELEASE.txt ${PREFIX}/share/doc/hdf5
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hdf5/html
	# avoid installing the Makefile and Makefile.in's  They are not needed
	cd ${WRKSRC}/doc/html && pax -s '/.*Makefile.*//' -rwpm . ${PREFIX}/share/doc/hdf5/html
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/hdf5/html

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
