# $NetBSD: Makefile,v 1.53 2020/01/08 12:30:34 nia Exp $

COMMENT=	Hierarchical Data Format (new generation)

INSTALLATION_DIRS=	bin lib include
INSTALLATION_DIRS+=	share/doc/hdf5
INSTALLATION_DIRS+=	share/examples/hdf5/c

post-install:
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
