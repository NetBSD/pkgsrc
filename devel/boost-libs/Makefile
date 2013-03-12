# $NetBSD: Makefile,v 1.25 2013/03/12 19:28:08 martin Exp $

BOOST_PACKAGE=		libs
BOOST_COMMENT=		(binary libraries)
BOOST_CONFIG=		installed
BOOST_INSTALL_LIBS=	yes

.include "../../meta-pkgs/boost/Makefile.common"

INSTALLATION_DIRS+=	lib

BJAM_ARGS+=		--without-python
PLIST_VARS+=		context

.if !empty(OPSYS:MNetBSD) && !empty(MACHINE_ARCH:Msparc64)
BJAM_ARGS+=		pch=off
.elif !empty(MACHINE_ARCH:Malpha) || !empty(MACHINE_ARCH:Mm68k)
BJAM_ARGS+=		--without-context
.endif

.if empty(BJAM_ARGS:M--without-context)
PLIST.context=		yes
.endif

UNLIMIT_RESOURCES+=	stacksize

.include "../../devel/boost-jam/bjam.mk"

do-build: bjam-build

do-install: boost-install-libs

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
