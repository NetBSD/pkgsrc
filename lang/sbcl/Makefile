# $NetBSD: Makefile,v 1.15 2007/11/07 17:34:18 jonb Exp $

DISTNAME=		${PKGNAME_NOREV}-source
PKGNAME=		sbcl-1.0.11
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sbcl/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jonb@NetBSD.org
HOMEPAGE=		http://www.sbcl.org/
COMMENT=		SBCL, a Common Lisp implementation

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-i386
# It should be possible to have SBCL working on amd64, powerpc,
# sparc, alpha, mips, and HPPA hardware also, but they probably
# need a bit of porting work done in SBCL itself.
# In addition, SBCL should also work on Linux, Darwin, Solaris,
# FreeBSD, OpenBSD, and possibly Win32, OSF/1, HP-UX, and Irix.

USE_TOOLS+=		gmake gtar:run
PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}/

#
# Bootstrap section.
#
# SBCL needs an existing Common Lisp system to build it...
# Currently allowed systems are CLisp, CMUCL, OpenMCL, and SBCL itself.
#
#  Note that CLisp 2.39nb1 worked two or three times when testing
#  this package and it failed to build SBCL twice.  It is also at
#  least twice as slow as using SBCL when building on an i386 platform.
#
#  I have never been able to get CLisp to build on a SPARC system, so
#  I had to cross build when trying to port SBCL to NetBSD/sparc.
#  I have reports that CLisp will build on PowerPC platforms, but is
#  unable to build SBCL.
#
#  If SBCL is installed in an unusual place when trying to build this
#  package, you may need to set the full path in SBCL_BOOT_SYSTEM and
#  build the package with "SBCL_HOME=/path/to/SBCL/core/image/ make"

#SBCL_BOOT_SYSTEM=	clisp			# CLisp
#SBCL_BOOT_SYSTEM=	"lisp -batch"		# CMUCL
#SBCL_BOOT_SYSTEM=	"openmcl --batch"	# OpenMCL
#SBCL_BOOT_SYSTEM=	sbcl			# SBCL

.if defined(SBCL_BOOT_SYSTEM) && ${SBCL_BOOT_SYSTEM} == clisp
BUILD_DEPENDS+=		clisp-[0-9]*:../../lang/clisp
.endif

.if !defined(SBCL_BOOT_SYSTEM)
PKG_FAIL_REASON+=	"Sorry, need a Common Lisp system.  See Makefile for details."
.endif

post-patch:
	${MV} ${WRKSRC}install.sh ${WRKSRC}install.sh.dist
	${SED} -e "s,@PREFIX@,${PREFIX}," ${WRKSRC}install.sh.dist > ${WRKSRC}install.sh
	${MV} ${WRKSRC}src/runtime/runtime.c ${WRKSRC}src/runtime/runtime.c.dist
	${SED} -e "s,@PREFIX@,${PREFIX}," ${WRKSRC}src/runtime/runtime.c.dist > ${WRKSRC}src/runtime/runtime.c
	${MV} ${WRKSRC}doc/sbcl.1 ${WRKSRC}doc/sbcl.1.dist
	${SED} -e "s,@PREFIX@,${PREFIX}," ${WRKSRC}doc/sbcl.1.dist > ${WRKSRC}doc/sbcl.1
	${MV} ${WRKSRC}contrib/asdf-install/installer.lisp ${WRKSRC}contrib/asdf-install/installer.lisp.dist
	${SED} -e "s,@GTAR@,${GTAR}," ${WRKSRC}contrib/asdf-install/installer.lisp.dist > ${WRKSRC}contrib/asdf-install/installer.lisp

do-build:
	cd ${WRKSRC} && ${SH} make.sh "${SBCL_BOOT_SYSTEM}"

do-install:
	cd ${WRKSRC} && INSTALL_ROOT=${PREFIX} MAN_DIR=${PREFIX}/${PKGMANDIR} ${SH} install.sh

.include "../../mk/bsd.pkg.mk"
