# $NetBSD: Makefile,v 1.58 2026/11/11 11:52:34 wiz Exp $

COMMENT=	Hierarchical Data Format (new generation)
PKGREVISION=	2

INSTALLATION_DIRS=	bin lib include
INSTALLATION_DIRS+=	share/doc/hdf5
INSTALLATION_DIRS+=	share/examples/hdf5/c

.include "Makefile.common"
.include "options.mk"

#SUBST_FILES.unwrap+=	${DESTDIR}${PREFIX}/bin/h5cc

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
