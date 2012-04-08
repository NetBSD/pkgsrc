# $NetBSD: Makefile,v 1.27.2.1 2012/04/08 09:18:55 sbd Exp $

PKGNAME=	gcc3${GCC3_PKGMODIF}-java-${GCC_VERSION}
COMMENT=	GNU Compiler Collection, v3 - Java compiler

PKG_DESTDIR_SUPPORT=	user-destdir

BROKEN=	Unbuildable for years and obsolete.

BUILDLINK_API_DEPENDS.gcc3cxx+=	gcc3${GCC3_PKGMODIF}-c++-${GCC_VERSION}{,nb*}
BUILDLINK_DEPMETHOD.gcc3cxx+=	full

INFO_FILES=	# PLIST

INSTLIBS=	libjava/lib-org-w3c-dom.la				\
		libjava/lib-org-xml-sax.la				\
		libjava/libgcj.la

.include "../../lang/gcc3/language.mk"

CONFIGURE_ARGS+=	--enable-languages="java"
CONFIGURE_ARGS+=	--with-system-zlib

# done manually in do-build
#UNLIMIT_RESOURCES=	datasize

USE_TOOLS+=		awk:run
REPLACE_INTERPRETER+=	awk
REPLACE.awk.old=	/bin/awk
REPLACE.awk.new=	${AWK}
REPLACE_FILES.awk+=	libjava/addr2name.awk

do-build:
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} java
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		GCC_FOR_TARGET=gcc \
		${GMAKE} configure-target-libjava
	[ -f ${WRKSRC}/${GCC_PLATFORM}/libjava/Makefile ] || ${FALSE}
	${ULIMIT_CMD_datasize}; cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${GMAKE} all-target-libjava

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/jc1 ${DESTDIR}${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/gcj ${DESTDIR}${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/jvgenmain ${DESTDIR}${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/gcjh ${DESTDIR}${GCC_ARCHDIR}
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${GMAKE} \
		java.install-common java.install-info
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${GMAKE} \
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
CONFIGURE_ENV+=		CFLAGS=${CONFIG_CFLAGS:Q} CPPFLAGS=${CONFIG_CPPFLAGS:Q}
.  endif
.endif
