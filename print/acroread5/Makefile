# $NetBSD: Makefile,v 1.5.2.1 2003/06/24 09:51:19 grant Exp $

DISTNAME=	acroread5	# Overridden below
PKGNAME=	acroread5-5.07
CATEGORIES=	print
MASTER_SITES=	ftp://ftp-pac.adobe.com/pub/adobe/acrobatreader/unix/5.x/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.adobe.com/prodindex/acrobat/readstep.html
COMMENT=	View, distribute and print PDF documents

RESTRICTED=	"Original installer required to redistribute."
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
LICENSE=	adobe-acrobat-license

CHECK_SHLIBS=	NO
NO_BUILD=	YES
SHLIB_HANDLING=	NO

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}

ONLY_FOR_PLATFORM=	*-*-i386 SunOS-*-sparc

# Default (overridden below)
PLATFORM=	unknown

.if ${OPSYS} == "NetBSD"
. if (${MACHINE_ARCH} == "i386")
DEPENDS=	suse_x11>=6.1:../../emulators/${SUSE_DIR_PREFIX}_x11
DISTNAME=	linux-507
PLATFORM=	intellinux
. elif (${MACHINE_ARCH} == "sparc")
.  if !exists(/emul/svr4/usr/lib/ld.so)
PKG_FAIL_REASON= '${PKGNAME} requires Solaris libraries - see compat_svr4(8)'
.  endif
DISTNAME=	sol-507
PLATFORM=	sparcsolaris
. endif
.elif ${OPSYS} == "SunOS"
DISTNAME=	sol-507
PLATFORM=	sparcsolaris
.endif

PLIST_SUBST+=	PLATFORM=${PLATFORM}

PLIST_SRC=	${PKGDIR}/PLIST.pre
.if ${MACHINE_ARCH} == "sparc"
PLIST_SRC+=	${PKGDIR}/PLIST.${MACHINE_ARCH}
.endif
PLIST_SRC+=	${PKGDIR}/PLIST.post

NS_PLUGINS_DIR=	${PREFIX}/lib/netscape/plugins

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
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${PREFIX}/Acrobat5/Browsers/${PLATFORM}/nppdf.so \
		${NS_PLUGINS_DIR}
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat5/Reader/license.txt"

.include "../../emulators/suse_linux/Makefile.application"
