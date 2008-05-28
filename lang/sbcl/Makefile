# $NetBSD: Makefile,v 1.16 2008/05/28 14:06:31 jonb Exp $

.include "../../mk/bsd.prefs.mk"

DISTNAME=		${PKGNAME_NOREV}-source
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			sbcl-${OPSYS}-${MACHINE_ARCH}-${OS_VERSION}.tgz
PKGNAME=		sbcl-1.0.16
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sbcl/}
EXTRACT_SUFX=		.tar.bz2
SITES.sbcl-${OPSYS}-${MACHINE_ARCH}-${OS_VERSION}.tgz= \
			ftp://ftp.NetBSD.org/pub/NetBSD/misc/jonb/sbcl/

MAINTAINER=		jonb@NetBSD.org
HOMEPAGE=		http://www.sbcl.org/
COMMENT=		SBCL, a Common Lisp implementation

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-i386

# SBCL creates a new release with minor updates and fixes every
# month.  The maintainer of this package does not have the time
# to build, test, update, etc. this package that often.  If you
# would like a newer (or older) version, this works very often:
# 1) change the PKGNAME variable above as desired
# 2) make fetch && make makesum && make package

# It should be possible to have SBCL working on amd64, powerpc,
# sparc, alpha, mips, and HPPA hardware also, but they probably
# need a bit of porting work done in SBCL itself.
# In addition, SBCL should also work on Linux, Darwin, Solaris,
# FreeBSD, OpenBSD, and possibly Win32, OSF/1, HP-UX, and Irix.

# SBCL needs an existing Common Lisp system to build it...
# In theory CLisp, CMUCL, OpenMCL, and SBCL itself should work.
# In practice, CLisp has been a PITA, while CMUCL and OpenMCL
# haven't been ported to NetBSD.  That leaves SBCL itself to
# do the build, so pull in a working binary package of SBCL
# along with the sources when building.

USE_TOOLS+=		gmake gtar:run
PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}/

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	pre-configure
SUBST_MESSAGE.fix-paths=fixing pathnames
SUBST_FILES.fix-paths=	install.sh src/runtime/runtime.c doc/sbcl.1
SUBST_SED.fix-paths=	-e 's,@PREFIX@,${PREFIX},g'

SUBST_CLASSES+=		fix-gtar
SUBST_STAGE.fix-gtar=	pre-configure
SUBST_MESSAGE.fix-gtar=	fixing gtar references
SUBST_FILES.fix-gtar=	contrib/asdf-install/installer.lisp
SUBST_SED/fix-gtar=	-e 's,@GTAR@.${GTAR},g'

do-build:
	export SBCL_HOME=${WRKDIR}/lib/sbcl/ \
	&& cd ${WRKSRC} \
	&& ${SH} make.sh ${WRKDIR}/bin/sbcl

# Rather not do this, but the file names seem to be hash values of
# timestamps or something and the pkgsrc system does *not* like
# randomly named and always changing file names
post-build:
	${RM} -rf ${WRKSRC}/contrib/sb-cover/test-output

do-install:
	cd ${WRKSRC} \
	&& INSTALL_ROOT=${PREFIX} \
	   MAN_DIR=${PREFIX}/${PKGMANDIR} \
	   ${SH} install.sh

.include "../../mk/bsd.pkg.mk"
