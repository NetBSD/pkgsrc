# $NetBSD: Makefile,v 1.17 2005/06/16 06:58:00 jlam Exp $

PKGNAME=	gcc3${GCC3_PKGMODIF}-java-${GCC_VERSION}
COMMENT=	GNU Compiler Collection, v3 - Java compiler

BUILDLINK_DEPENDS.gcc3cxx+=	gcc3${GCC3_PKGMODIF}-c++-${GCC_VERSION}{,nb*}
BUILDLINK_DEPMETHOD.gcc3cxx+=	full

INFO_FILES=	gcj.info

INSTLIBS=	libjava/lib-org-w3c-dom.la				\
		libjava/lib-org-xml-sax.la				\
		libjava/libgcj.la

.include "../../lang/gcc3/language.mk"

CONFIGURE_ARGS+=	--enable-languages="java"
CONFIGURE_ARGS+=	--with-system-zlib

# done manually in do-build
#UNLIMIT_RESOURCES=	datasize

do-build:
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} java
	${ULIMIT_CMD_datasize}; cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${GMAKE} all-target-libjava

do-install:
	${INSTALL_PROGRAM_DIR} ${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/jc1 ${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/gcj ${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/jvgenmain ${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/gcjh ${GCC_ARCHDIR}
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		java.install-common java.install-info
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		install-target-libjava

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/gcc3-c++/buildlink3.mk"
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
CONFIG_CFLAGS=		${CFLAGS:C/-O[0-9]*//g}
CONFIG_CPPFLAGS=	${CPPFLAGS:C/-O[0-9]*//g}
CONFIGURE_ENV+=		CFLAGS="${CONFIG_CFLAGS}" CPPFLAGS="${CONFIG_CPPFLAGS}"
.  endif
.endif
