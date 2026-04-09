# $NetBSD: Makefile,v 1.56 2026/04/09 07:11:41 wiz Exp $

COMMENT=	Hierarchical Data Format (new generation)

INSTALLATION_DIRS=	bin lib include
INSTALLATION_DIRS+=	share/doc/hdf5
INSTALLATION_DIRS+=	share/examples/hdf5/c

.include "Makefile.common"
.include "options.mk"

#SUBST_FILES.unwrap+=	${DESTDIR}${PREFIX}/bin/h5cc

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
