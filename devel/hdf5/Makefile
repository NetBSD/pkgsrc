# $NetBSD: Makefile,v 1.55 2025/03/19 09:18:14 adam Exp $

COMMENT=	Hierarchical Data Format (new generation)

INSTALLATION_DIRS=	bin lib include
INSTALLATION_DIRS+=	share/doc/hdf5
INSTALLATION_DIRS+=	share/examples/hdf5/c

.include "Makefile.common"
.include "options.mk"

SUBST_FILES.unwrap+=	${DESTDIR}${PREFIX}/bin/h5cc
.if empty(PKG_OPTIONS:Mthreads)
SUBST_FILES.unwrap+=	${DESTDIR}${PREFIX}/bin/h5hlcc
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
