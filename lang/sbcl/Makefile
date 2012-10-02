# $NetBSD: Makefile,v 1.44 2012/10/02 19:20:45 asau Exp $

DISTNAME=		${PKGNAME_NOREV}-source
PKGNAME=		sbcl-1.1.0
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sbcl/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@NetBSD.org
HOMEPAGE=		http://www.sbcl.org/
COMMENT=		SBCL, a Common Lisp implementation

# SBCL creates a new release with minor updates and fixes every
# month.  The maintainer of this package does not have the time
# to build, test, update, etc. this package that often.  If you
# would like a newer (or older) version, this works very often:
# 1) change the PKGNAME variable above as desired
# 2) make fetch && make makesum && make package

USE_TOOLS+=		gmake gtar:run
PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/bsd.prefs.mk"

#
# Bootstrap section.
#
# SBCL needs an existing Common Lisp system to build it...
# Currently allowed systems are CLISP, CMUCL, OpenMCL, and SBCL itself.
#
#  If SBCL is installed in an unusual place when trying to build this
#  package, you may need to set the full path in SBCL_BOOT_SYSTEM and
#  build the package with "SBCL_HOME=/path/to/SBCL/core/image/ make"

#SBCL_BOOT_SYSTEM=	clisp			# CLisp
#SBCL_BOOT_SYSTEM=	"lisp -batch"		# CMUCL
#SBCL_BOOT_SYSTEM=	"openmcl --batch"	# OpenMCL
#SBCL_BOOT_SYSTEM=	sbcl			# SBCL

.if !defined(SBCL_BOOT_SYSTEM)
# Use "clisp -ansi -on-error abort" to make the build more reproducible,
# per Christophe Rhodes:
SBCL_BOOT_SYSTEM=	clisp -norc -ansi -on-error abort
BUILD_DEPENDS+=		clisp-[0-9]*:../../lang/clisp
UNLIMIT_RESOURCES=	datasize
.elif ${SBCL_BOOT_SYSTEM} == clisp
BUILD_DEPENDS+=		clisp-[0-9]*:../../lang/clisp
UNLIMIT_RESOURCES=	datasize
.elif ${SBCL_BOOT_SYSTEM} == sbcl
# Get bootstrap version:
BUILD_DEPENDS+=		sbcl-[0-9]*:../../lang/sbcl
.endif


SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		install.sh src/runtime/runtime.c doc/sbcl.1
SUBST_SED.fix-paths=		-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.fix-paths+=           -e 's,/var/log,${VARBASE}/log,g'

SUBST_CLASSES+=			fix-gtar
SUBST_STAGE.fix-gtar=		pre-configure
SUBST_MESSAGE.fix-gtar=		Fixing GNU tar references.
SUBST_FILES.fix-gtar=		contrib/asdf-install/installer.lisp
SUBST_SED.fix-gtar=		-e 's,@GTAR@,${GTAR},'

do-build:
	cd ${WRKSRC} && ${SH} make.sh --prefix=${PREFIX} --xc-host=${SBCL_BOOT_SYSTEM:Q}
post-build:
	cd ${WRKSRC} && ${RM} -f contrib/sb-cover/test-output/*

do-install:
	cd ${WRKSRC} && BUILD_ROOT=${DESTDIR:Q} INSTALL_ROOT=${PREFIX:Q} MAN_DIR=${PREFIX:Q}/${PKGMANDIR} ${SH} install.sh
	rm -f $(DESTDIR)$(PREFIX)/lib/sbcl/sb-posix/test-output/write-test.txt
	rm -f $(DESTDIR)$(PREFIX)/lib/sbcl/sb-posix/test-output/read-test.txt
	rm -f $(DESTDIR)$(PREFIX)/lib/sbcl/asdf-install/installer.lisp.orig

do-test:
	cd ${WRKSRC}/tests && ${SH} ./run-tests.sh

.if $(LOWER_ARCH) == "amd64" || $(LOWER_ARCH) == "x86_64"
PLIST_SUBST+=	SUFX64=-64
.else
PLIST_SUBST+=	SUFX64=
.endif

.include "../../mk/bsd.pkg.mk"
