# $NetBSD: Makefile,v 1.27 2005/06/17 03:50:30 jlam Exp $

PKGNAME=	acroread3-3.01
CATEGORIES=	print
MASTER_SITES=	ftp://ftp-pac.adobe.com/pub/adobe/acrobatreader/unix/3.x/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.adobe.com/prodindex/acrobat/readstep.html
COMMENT=	View, distribute and print PDF documents

RESTRICTED=	"Original installer required to redistribute."
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
LICENSE=		adobe-acrobat-license

WRKSRC=		${WRKDIR}
NO_BUILD=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.if (${MACHINE_ARCH} == "i386")
DEPENDS=	suse_libc5>=6.3:../../emulators/${SUSE_DIR_PREFIX}_libc5
DEPENDS=	suse_x11>=6.3:../../emulators/${SUSE_DIR_PREFIX}_x11
DISTNAME=	acroread_linux_301
PLATFORM=	intellinux
CHECK_SHLIBS=	no
.elif (${MACHINE_ARCH} == "alpha")
.if !exists(/emul/osf1/sbin/loader)
PKG_FAIL_REASON= "${PKGNAME} requires Digital UNIX libraries - see compat_osf1(8)"
.endif
DISTNAME=	acroread_osf_301
PLATFORM=	alphaosf
LDD?=		${TRUE}
.elif (${MACHINE_ARCH} == "sparc")
.if !exists(/emul/sunos/usr/lib/ld.so)
PKG_FAIL_REASON= "${PKGNAME} requires SunOS libraries - see compat_sunos(8)"
.endif
DISTNAME=	acroread_sunos_301
PLATFORM=	sparcsun
LDD?=		${TRUE}
.else
DISTNAME=	${PKGNAME}
LDD?=		${TRUE}
.endif
ONLY_FOR_PLATFORM=	*-*-i386 *-*-sparc # *-*-alpha
.elif ${OPSYS} == "SunOS"
DISTNAME=	acroread_solaris_301
PLATFORM=	sparcsolaris
LDD?=		${TRUE}
post-patch:
	${CHMOD} -R o+rwx ${WRKSRC}
.else
DISTNAME=	${PKGNAME}
LDD?=		${TRUE}
.endif

PLIST_SUBST+=	PLATFORM=${PLATFORM}

INSTALLATION_DIRS=	bin

pre-install:
#	${SED} -e 's|@PLATFORM@|${PLATFORM}|g' ${PKGDIR}/PLIST > ${PLIST_SRC}

do-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/Acrobat3
	@${ECHO} accept | PAGER=${CAT} ReadInstallDir=${PREFIX}/Acrobat3 ${WRKSRC}/INSTALL

post-install:
	@cd ${PREFIX}/Acrobat3/bin && \
	  ${PATCH} ${_PATCH_BACKUP_ARG} .orig --quiet < ${FILESDIR}/acroread.diff && \
	  ${INSTALL_SCRIPT} ${PREFIX}/Acrobat3/bin/acroread \
	     ${PREFIX}/bin/acroread3 && ${RM} acroread.orig
	@${CHMOD} +x ${PREFIX}/bin/acroread3
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat3/Reader/License.pdf"

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
