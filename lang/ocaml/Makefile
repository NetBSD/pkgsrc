# $NetBSD: Makefile,v 1.37 2005/06/07 00:59:48 minskim Exp $

.include "Makefile.common"

CONFIGURE_ARGS+=	-no-tk
CONFIGURE_ENV+=		disable_x11=yes
CONFIGURE_ENV+=		BDB_LIBS=${BDB_LIBS} \
			BDB_BUILTIN=${USE_BUILTIN.${BDB_TYPE}}

CPPFLAGS+=		-DDB_DBM_HSEARCH

BUILD_TARGET=		world
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc")
BUILD_TARGET+=	opt opt.opt
PLIST_SRC=	${PKGDIR}/PLIST.opt
.  if ${OPSYS} != "Darwin"
PLIST_SRC+=	${PKGDIR}/PLIST.prof
.  endif
PLIST_SRC+=	${PKGDIR}/PLIST
.endif

.if ${OPSYS} == "Darwin"
PLIST_SRC+=	${PKGDIR}/PLIST.stub
.endif

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
