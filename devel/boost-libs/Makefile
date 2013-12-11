# $NetBSD: Makefile,v 1.26 2013/12/11 17:01:06 jperkin Exp $

BOOST_PACKAGE=		libs
BOOST_COMMENT=		(binary libraries)
BOOST_CONFIG=		installed
BOOST_INSTALL_LIBS=	yes

.include "../../meta-pkgs/boost/Makefile.common"

INSTALLATION_DIRS+=	lib

BJAM_ARGS+=		--without-python
PLIST_VARS+=		context log

.if !empty(OPSYS:MNetBSD) && !empty(MACHINE_ARCH:Msparc64)
BJAM_ARGS+=		pch=off
.elif !empty(MACHINE_ARCH:Malpha) || !empty(MACHINE_ARCH:Mm68k)
BJAM_ARGS+=		--without-context
.endif

.if empty(BJAM_ARGS:M--without-context)
PLIST.context=		yes
.endif

# Darwin GCC is unable to build Boost.Log
.if ${OPSYS} == "Darwin" && !empty(PKGSRC_COMPILER:Mgcc)
BJAM_ARGS+=		--without-log
.else
PLIST.log=		yes
.endif

UNLIMIT_RESOURCES+=	stacksize

.include "../../devel/boost-jam/bjam.mk"

do-build: bjam-build

do-install: boost-install-libs

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
