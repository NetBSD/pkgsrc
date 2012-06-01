# $NetBSD: Makefile,v 1.21 2012/06/01 10:26:09 jdc Exp $

BOOST_PACKAGE=		libs
BOOST_COMMENT=		(binary libraries)
BOOST_CONFIG=		installed
BOOST_INSTALL_LIBS=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/boost/Makefile.common"

BJAM_ARGS+=		--without-python
.if !empty(OPSYS:MNetBSD) && !empty(MACHINE_ARCH:Msparc64)
BJAM_ARGS+=		pch=off
.endif

.include "../../devel/boost-jam/bjam.mk"

# Hack: gcc on sparc64 catches an illegal instruction compiling graphml.o
.if ${MACHINE_ARCH} == "sparc64" && !empty(CC_VERSION:Mgcc*)
BUILDLINK_TRANSFORM+=   rename:-O3:-O1
.endif

do-build: bjam-build

do-install: boost-install-libs

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
