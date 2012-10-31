# $NetBSD: Makefile,v 1.24 2012/10/31 11:16:42 asau Exp $

BOOST_PACKAGE=		libs
BOOST_COMMENT=		(binary libraries)
BOOST_CONFIG=		installed
BOOST_INSTALL_LIBS=	yes

.include "../../meta-pkgs/boost/Makefile.common"

INSTALLATION_DIRS+=	lib

BJAM_ARGS+=		--without-python
.if !empty(OPSYS:MNetBSD) && !empty(MACHINE_ARCH:Msparc64)
BJAM_ARGS+=		pch=off
.endif

UNLIMIT_RESOURCES+=	stacksize

.include "../../devel/boost-jam/bjam.mk"

do-build: bjam-build

do-install: boost-install-libs

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
