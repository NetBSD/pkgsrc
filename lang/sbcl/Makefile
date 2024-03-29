# $NetBSD: Makefile,v 1.102 2023/11/28 15:03:55 rjs Exp $

DISTNAME=		${PKGNAME_NOREV}-source
PKGNAME=		sbcl-2.3.11
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sbcl/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.sbcl.org/
COMMENT=		SBCL, a Common Lisp implementation
LICENSE=		mit

# SBCL creates a new release with minor updates and fixes every
# month.  The maintainer of this package does not have the time
# to build, test, update, etc. this package that often.  If you
# would like a newer (or older) version, this works very often:
# 1) change the PKGNAME variable above as desired
# 2) make fetch && make makesum && make package

USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

MKPIE_SUPPORTED=no

.include "../../mk/bsd.prefs.mk"

#
# Bootstrap section.
#
# SBCL needs an existing Common Lisp system to build it...
# Currently allowed systems are CLISP, CMUCL, OpenMCL, ABCL and SBCL itself.
#
#  If SBCL is installed in an unusual place when trying to build this
#  package, you may need to set the full path in SBCL_BOOT_SYSTEM and
#  build the package with "SBCL_HOME=/path/to/SBCL/core/image/ make"

#SBCL_BOOT_SYSTEM=	clisp			# CLisp
#SBCL_BOOT_SYSTEM=	"lisp -batch"		# CMUCL
#SBCL_BOOT_SYSTEM=	"openmcl --batch"	# OpenMCL
#SBCL_BOOT_SYSTEM=	sbcl			# SBCL
#SBCL_BOOT_SYSTEM=	abcl			# ABCL

.if !defined(SBCL_BOOT_SYSTEM)
# Use "clisp -ansi -on-error abort" to make the build more reproducible,
# per Christophe Rhodes:
SBCL_BOOT_SYSTEM=	clisp -norc -ansi -on-error abort
TOOL_DEPENDS+=		clisp-[0-9]*:../../lang/clisp
UNLIMIT_RESOURCES=	datasize
.elif ${SBCL_BOOT_SYSTEM} == abcl
TOOL_DEPENDS+=		abcl-[0-9]*:../../lang/abcl
.endif

PLIST_VARS+=		simd

.if ${MACHINE_ARCH} == "x86_64"
PLIST.simd=		yes
.endif

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		doc/sbcl.1
SUBST_VARS.fix-paths=		PREFIX
SUBST_SED.fix-paths+=		-e 's,/var/log,${VARBASE}/log,g'

SUBST_CLASSES+=			fix-bins
SUBST_STAGE.fix-bins=		pre-configure
SUBST_FILES.fix-bins=		src/runtime/Config.x86-64-sunos
SUBST_FILES.fix-bins+=		src/runtime/Config.x86-sunos
SUBST_FILES.fix-bins+=		contrib/asdf-module.mk
SUBST_SED.fix-bins=		-e 's,nm ,/usr/bin/nm ,'
SUBST_SED.fix-bins+=		-e 's,ggrep,grep,'
SUBST_SED.fix-bins+=		-e 's,=199506L,=200112L,'
SUBST_SED.fix-bins+=		-e 's,=500,=600,'

BUILD_DEFS+=			VARBASE

.if defined(TOOLS_PLATFORM.paxctl)
SBCL_PAXCTL=	${PAXCTL} +m
MAKE_ENV+=	SBCL_PAXCTL=${SBCL_PAXCTL:Q}
.endif

INSTALL_ENV+=	BUILD_ROOT=${DESTDIR:Q}
INSTALL_ENV+=	INSTALL_ROOT=${PREFIX:Q}
INSTALL_ENV+=	MAN_DIR=${PREFIX:Q}/${PKGMANDIR}

NOT_PAX_MPROTECT_SAFE+=	bin/sbcl

.if !empty(MACHINE_PLATFORM:MSunOS-*-i386)
SBCL_ARCH_ARGS=		"--arch=x86"
.elif !empty(MACHINE_PLATFORM:MSunOS-*-x86_64)
SBCL_ARCH_ARGS=		"--arch=x86-64"
.endif

do-build:
	${RUN} ${_ULIMIT_CMD} \
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${SH} make.sh --prefix=${PREFIX} ${SBCL_ARCH_ARGS} --xc-host=${SBCL_BOOT_SYSTEM:Q}

post-build:
	cd ${WRKSRC} && ${RM} -f contrib/sb-cover/test-output/*

do-install:
	${RUN} ${_ULIMIT_CMD} \
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${INSTALL_ENV} ${SH} install.sh
	${RM} -f ${DESTDIR}${PREFIX}/lib/sbcl/sb-posix/test-output/write-test.txt
	${RM} -f ${DESTDIR}${PREFIX}/lib/sbcl/sb-posix/test-output/read-test.txt
	${RM} -f ${DESTDIR}${PREFIX}/lib/sbcl/asdf-install/installer.lisp.orig

do-test:
#	for f in compiler.pure.lisp interface.pure.lisp compiler.impure.lisp debug.impure.lisp interface.impure.lisp; do mv ${WRKSRC}/tests/$$f ${WRKSRC}/tests/$$f.off || :; done
	${RUN} ${_ULIMIT_CMD} \
	cd ${WRKSRC}/tests && ${PKGSRC_SETENV} ${TEST_ENV} ${SH} ./run-tests.sh

.if ${MACHINE_ARCH} == "x86_64"
PLIST_SUBST+=	SUFX64=-64
.else
PLIST_SUBST+=	SUFX64=
.endif

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
