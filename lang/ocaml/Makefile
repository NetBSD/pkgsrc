# $NetBSD: Makefile,v 1.145 2022/06/24 12:30:09 gdt Exp $

.include "Makefile.common"

TEST_PROGRAM=		ocamltest
MAKE_JOBS_SAFE=		no
UNLIMIT_RESOURCES=	stacksize

USE_TOOLS+=		bash
USE_LANGUAGES+=		c
USE_LIBTOOL=		yes
USE_GNU_CONFIGURE_HOST=	no

#USE_GCC_RUNTIME=	yes

.include "options.mk"
.include "native.mk"

# Options

.if ${OCAML_USE_OPT_COMPILER} == "yes"
CONFIGURE_ARGS+=	--enable-native-compiler
BUILD_TARGET=		world.opt
.else
CONFIGURE_ARGS+=	--disable-native-compiler
BUILD_TARGET=		world
.endif

# configure: error: fma does not work, enable emulation with --enable-imprecise-c99-float-ops
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-imprecise-c99-float-ops
.endif

# This is needed because ${WRKSRC}/build/partial-install.sh uses
# $PWD as part of its script.  However, with /bin/sh on SunOS
# (cd work/foo-1.0 && echo $PWD) will show that the value of PWD is
# set before the cd takes place and is then passed down.  So the end
# result is when ./build/partial-install.sh is called, PWD is set
# to /usr/pkgsrc/devel/ocaml instead of ${WRKSRC}.  /bin/ksh, which
# is what ${SH} is on SunOS, doesn't exhibit this behaviour.
.if ${OPSYS} == "SunOS"
INSTALL_MAKE_FLAGS+=	SHELL=${SH:Q}
.endif

INSTALLATION_DIRS=	share/doc/ocaml

OPSYSVARS+=		EXTRA_RT_LIBS
EXTRA_RT_LIBS.NetBSD=	-lcurses
EXTRA_RT_LIBS.*=

PRINT_PLIST_AWK+=	{ gsub(/lib\/ocaml\/${PKGMANDIR:S|/|\\/|}/, "lib/ocaml/$${PKGMANDIR}"); }

do-test:
	cd ${WRKSRC} && ${MAKE_PROGRAM} ${TEST_PROGRAM}
	cd ${WRKSRC}/testsuite && ${MAKE_PROGRAM} all

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
	for f in ${DESTDIR}${PREFIX}/lib/ocaml/*.so \
		${DESTDIR}${PREFIX}/lib/ocaml/stublibs/*.so; do \
		install_name_tool -id `${ECHO} $$f | ${SED} -e 's,${DESTDIR},,g'` $$f; \
	done
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
