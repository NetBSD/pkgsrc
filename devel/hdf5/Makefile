# $NetBSD: Makefile,v 1.52 2019/10/06 12:05:33 nia Exp $

COMMENT=	Hierarchical Data Format (new generation)

INSTALLATION_DIRS=	bin lib include
INSTALLATION_DIRS+=	share/doc/hdf5
INSTALLATION_DIRS+=	share/examples/hdf5/c

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/src/misc/h5cc \
		${DESTDIR}${PREFIX}/bin/
	libtool   --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/tools/src/misc/h5clear \
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/tools/src/misc/h5redeploy.in \
		${DESTDIR}${PREFIX}/bin/h5redeploy
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING \
		release_docs/RELEASE.txt \
		release_docs/HISTORY-1_10.txt \
		release_docs/HISTORY-1_8_0-1_10_0.txt \
		release_docs/HISTORY-1_8.txt \
		release_docs/HISTORY-1_0-1_8_0_rc3.txt \
		${DESTDIR}${PREFIX}/share/doc/hdf5/

.include "Makefile.common"
.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
