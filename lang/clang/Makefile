# $NetBSD: Makefile,v 1.23 2013/12/24 05:57:44 richard Exp $

DISTNAME=	clang-3.3
CATEGORIES=	lang
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/
DISTFILES=	llvm-${PKGVERSION_NOREV}.src.tar.gz \
		cfe-${PKGVERSION_NOREV}.src.tar.gz

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/llvm-${PKGVERSION_NOREV}.src

USE_LANGUAGES=		c c++
USE_TOOLS+=		chown gmake groff pod2html pod2man
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-assertions
CONFIGURE_ARGS+=	--disable-bindings	# disable OCaml
CONFIGURE_ARGS+=	--disable-timestamps
CONFIGURE_ARGS+=	--enable-optimized
#CONFIGURE_ARGS+=	--enable-shared

MAKE_DIRS+=		etc/llvm

INSTALLATION_DIRS=	bin lib libexec

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

TEST_TARGET=	check unittests

.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_SHLIB_TYPE} == "dylib"
PLIST_SUBST+=		SOEXT="dylib"
.else
PLIST_SUBST+=		SOEXT="so"
.endif

.include "../../mk/compiler.mk"

.if ${OPSYS} == "SunOS" && !empty(PKGSRC_COMPILER:Mgcc)
# This should probably be in hacks, but since clang hardcodes gcc paths
# put this here so it can be removed when clang matures.
# cxa_finalize.o is no longer necessary with libc.so >= ILLUMOS_0.5
TEST_ILLUMOS_3849!=\
	if /usr/bin/elfdump -v /lib/libc.so |\
	  ${GREP} -q 'ILLUMOS_0.5' ; then	\
		${ECHO} 1;	\
	else ${ECHO} 0;	\
	fi

#doesn't seem to be needed anymore, but may be dependent on
#a recent version of solaris (illumos) ld.
#
#CFLAGS.SunOS+=		-mimpure-text

SUBST_CLASSES+=				fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute gcc paths for SunOS.
SUBST_FILES.fix-paths=		tools/clang/lib/Driver/Tools.cpp
.  if defined(_GCC_ARCHDIR)
SUBST_SED.fix-paths=		-e 's,/usr/gcc/4.5/lib/gcc/,${_GCC_ARCHDIR}/,g'
.  else
LIBGCCDIR!=	${CC} -print-libgcc-file-name
ARCHDIR:=	${LIBGCCDIR:H}
SUBST_SED.fix-paths=		-e 's,/usr/gcc/4.5/lib/gcc/,${ARCHDIR}/,g'
.  endif
SUBST_SED.fix-paths+=		-e '/^.*i386.*getVendorName.*$$/{N;d;}'
SUBST_SED.fix-paths+=		-e 's,/4.5.2/amd64/,amd64/,g'
SUBST_SED.fix-paths+=		-e 's,"as","gas",g'
.  if exists(/usr/bin/ld)
SUBST_SED.fix-paths+=		-e 's,getToolChain().GetProgramPath("ld"),"/usr/bin/ld",g'
.  else
SUBST_SED.fix-paths+=		-e 's,getToolChain().GetProgramPath("ld"),"/usr/ccs/bin/ld",g'
.  endif
.  if ${TEST_ILLUMOS_3849}
SUBST_SED.fix-paths+=		-e 's,^.*cxa_finalize.*$$,		; //cxa_finalize.o,g'
.  endif
.endif

post-extract:
	mv ${WRKDIR}/cfe-${PKGVERSION_NOREV}.src ${WRKSRC}/tools/clang
.if ${OPSYS} == "SunOS"
	${ECHO} "int sun_ld_needs_a_symbol=0;" >> ${WRKSRC}/lib/Target/NVPTX/InstPrinter/NVPTXInstPrinter.cpp
.endif

.include "../../lang/python/tool.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
