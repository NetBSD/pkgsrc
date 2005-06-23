# $NetBSD: Makefile,v 1.1.1.1 2005/06/23 03:00:20 jonb Exp $

DISTNAME=		${PKGNAME}-source
PKGNAME=		sbcl-0.9.1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sbcl/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jonb@NetBSD.org
HOMEPAGE=		http://www.sbcl.org/
COMMENT=		SBCL, a Common Lisp implementation

ONLY_FOR_PLATFORM=	NetBSD-*-i386
# It should be possible to have SBCL working on amd64, powerpc,
# sparc, alpha, mips, and HPPA hardware also, but they probably
# need a bit of porting work done in SBCL itself.
# In addition, SBCL should also work on Linux, Darwin, Solaris,
# FreeBSD, OpenBSD, and possibly Win32, OSF/1, HP-UX, and Irix.

USE_TOOLS+=		gmake
PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${PKGNAME}/

#
# Bootstrap section.
#
# SBCL needs an existing Common Lisp system to build it...
# Currently allowed systems are CLisp, CMUCL, OpenMCL, and SBCL itself.
#
SBCL_BOOT_SYSTEM=	clisp
#SBCL_BOOT_SYSTEM=	"lisp -batch"
#SBCL_BOOT_SYSTEM=	"openmcl --batch"
#SBCL_BOOT_SYSTEM=	sbcl

.if defined(SBCL_BOOT_SYSTEM) && ${SBCL_BOOT_SYSTEM} == clisp
BUILD_DEPENDS+=		clisp-[0-9]*:../../lang/clisp
.endif

.if !defined(SBCL_BOOT_SYSTEM)
PKG_SKIP_REASON=	"Sorry, need a Common Lisp system"
.endif

post-patch:
	${MV} ${WRKSRC}/install.sh ${WRKSRC}/install.sh.dist
	${SED} -e "s,@PREFIX@,${PREFIX}," ${WRKSRC}/install.sh.dist > ${WRKSRC}/install.sh
	${MV} ${WRKSRC}/src/runtime/runtime.c ${WRKSRC}/src/runtime/runtime.c.dist
	${SED} -e "s,@PREFIX@,${PREFIX}," ${WRKSRC}/src/runtime/runtime.c.dist > ${WRKSRC}/src/runtime/runtime.c
	${MV} ${WRKSRC}/doc/sbcl.1 ${WRKSRC}/doc/sbcl.1.dist
	${SED} -e "s,@PREFIX@,${PREFIX}," ${WRKSRC}/doc/sbcl.1.dist > ${WRKSRC}/doc/sbcl.1

do-build:
	cd ${WRKSRC} && ${SH} make.sh "${SBCL_BOOT_SYSTEM}"

do-install:
	cd ${WRKSRC} && INSTALL_ROOT=${PREFIX} ${SH} install.sh

.include "../../mk/bsd.pkg.mk"
