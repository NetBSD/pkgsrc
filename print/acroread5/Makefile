# $NetBSD: Makefile,v 1.23 2004/11/07 12:32:04 markd Exp $

DISTNAME=	acroread5	# Overridden below
PKGNAME=	acroread5-5.09
CATEGORIES=	print
MASTER_SITES=	http://ardownload.adobe.com/pub/adobe/acrobatreader/unix/5.x/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.adobe.com/prodindex/acrobat/readstep.html
COMMENT=	View, distribute and print PDF documents

CONFLICTS+=	acroread-5.*

RESTRICTED=	"Original installer required to redistribute."
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
LICENSE=	adobe-acrobat-license

WRKSRC=		${WRKDIR}
CHECK_SHLIBS=	NO
NO_BUILD=	YES
SHLIB_HANDLING=	NO

.include "../../mk/bsd.prefs.mk"

ONLY_FOR_PLATFORM=	*-*-i386 *-*-sparc*

# Default (overridden below)
PLATFORM=	unknown

.if ${OPSYS} == "NetBSD"
. if (${MACHINE_ARCH} == "i386")
DEPENDS=	suse_x11>=6.1:../../emulators/${SUSE_DIR_PREFIX}_x11
DISTNAME=	linux-509
PLATFORM=	intellinux
. elif (${MACHINE_ARCH} == "sparc")
.  if !exists(/emul/svr4/usr/lib/ld.so)
PKG_FAIL_REASON= '${PKGNAME} requires Solaris libraries - see compat_svr4(8)'
.  endif
DISTNAME=	solaris-509
PLATFORM=	sparcsolaris
. elif (${MACHINE_ARCH} == "sparc64")
.  if !exists(/emul/svr4_32/usr/lib/ld.so)
PKG_FAIL_REASON= '${PKGNAME} requires Solaris libraries - see compat_svr4_32(8)'
.  endif
DISTNAME=	solaris-509
PLATFORM=	sparcsolaris
. endif
.elif ${OPSYS} == "Linux"
DISTNAME=	linux-509
PLATFORM=	intellinux
.elif ${OPSYS} == "SunOS"
DISTNAME=	solaris-509
PLATFORM=	sparcsolaris
.endif

PLIST_SUBST+=	PLATFORM=${PLATFORM}

PLIST_SRC=	${PKGDIR}/PLIST.pre
.if ${MACHINE_ARCH} == "sparc"
PLIST_SRC+=	${PKGDIR}/PLIST.${MACHINE_ARCH}
.endif
PLIST_SRC+=	${PKGDIR}/PLIST.post

BIN_PATCH=	${PATCH} --quiet ${_PATCH_BACKUP_ARG} .orig

do-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/Acrobat5
	@( ${ECHO} accept ) | PAGER=${CAT} ReadInstallDir=${PREFIX}/Acrobat5 ${WRKSRC}/INSTALL

post-install:
	@cd ${PREFIX}/Acrobat5/bin && \
	  ${BIN_PATCH} <${FILESDIR}/acroread.diff && \
	  ${INSTALL_SCRIPT} ${PREFIX}/Acrobat5/bin/acroread \
	     ${PREFIX}/bin/acroread5 && ${RM} -f acroread.orig
	${CHMOD} +x ${PREFIX}/bin/acroread5
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat5/Reader/license.txt"

# do not include the linux stuff if we are, for example, on a Solaris box
. if (${MACHINE_ARCH} == "i386")
.include "../../emulators/suse_linux/Makefile.application"
.endif
.include "../../mk/bsd.pkg.mk"
