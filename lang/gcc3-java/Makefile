# $NetBSD: Makefile,v 1.8 2003/12/03 11:28:55 drochner Exp $
#

PKGNAME=		gcc3${GCC3_PKGMODIF}-java-${GCC_VERSION}
COMMENT=		GNU Compiler Collection, version 3, Java compiler

INFO_FILES=		gcj.info

.include "../../lang/gcc3-c/buildaddon.mk"

BUILD_DEPENDS+=		gcc3${GCC3_PKGMODIF}-c++-3.3.2:../../lang/gcc3-c++
CONFIGURE_ARGS+=	--enable-languages="java"
CONFIGURE_ARGS+=	--with-system-zlib
# done manually in do-build
#UNLIMIT_RESOURCES=	datasize

do-build:
	(cd ${WRKSRC}/gcc && ${GMAKE} java)
	(${ULIMIT_CMD_datasize}; cd ${WRKSRC} && ${GMAKE} all-target-libjava)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/jc1 ${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/gcj ${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/jvgenmain ${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/gcjh ${GCC_ARCHDIR}
	(cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		java.install-common java.install-info)
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		install-target-libjava)

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

# On NetBSD, the gcc-2.95.3 for:
#
#     alpha
#
# have an optimization bug when compiling with -O2 that is tickled by:
#
#   java/parse.o
#
# note that we don't override CFLAGS and CPPFLAGS because we want the
# crosscompiled compiler to be build with optimization.  This only
# disables optimization for the stage 1 build.
#
.if ${OPSYS} == "NetBSD"
.  if ${MACHINE_ARCH} == "alpha"
CONFIG_CFLAGS=	${CFLAGS:C/-O[0-9]*//g}
CONFIG_CPPFLAGS=	${CPPFLAGS:C/-O[0-9]*//g}
CONFIGURE_ENV+=	CFLAGS="${CONFIG_CFLAGS}" CPPFLAGS="${CONFIG_CPPFLAGS}"
.  endif
.endif
