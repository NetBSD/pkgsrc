# $NetBSD: Makefile,v 1.46 2012/12/09 00:07:38 adam Exp $

PKGNAME=	hdf5-${HDF5_VER}
COMMENT=	Hierarchical Data Format (new generation)

INSTALLATION_DIRS=	bin lib include
INSTALLATION_DIRS+=	share/doc/hdf5
INSTALLATION_DIRS+=	share/examples/hdf5/c

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/misc/h5cc \
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/tools/misc/h5redeploy.in \
		${DESTDIR}${PREFIX}/bin/h5redeploy
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING \
		release_docs/RELEASE.txt \
		release_docs/HISTORY-1_8.txt \
		release_docs/HISTORY-1_0-1_8_0_rc3.txt \
		${DESTDIR}${PREFIX}/share/doc/hdf5/

.include "Makefile.common"
.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
