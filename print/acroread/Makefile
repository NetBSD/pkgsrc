# $NetBSD: Makefile,v 1.50 2006/09/04 19:27:56 hubertf Exp $

DISTNAME=	acroread	# Overridden below
PKGNAME=	acroread-4.05
PKGREVISION=	5
CATEGORIES=	print
MASTER_SITES=	ftp://ftp-pac.adobe.com/pub/adobe/acrobatreader/unix/4.x/ \
		http://download.adobe.com/pub/adobe/acrobatreader/unix/4.x/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.adobe.com/prodindex/acrobat/readstep.html
COMMENT=	View, distribute and print PDF documents

RESTRICTED=	Original installer required to redistribute.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
LICENSE=	adobe-acrobat-license

CHECK_SHLIBS_SUPPORTED=	no
NO_BUILD=		yes

.include "../../mk/bsd.prefs.mk"

# Default (should be overridden below)
PLATFORM=	unknown

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-1.4[L-Z]-sparc \
			NetBSD-1.[5-9]*-sparc NetBSD-[2-9]*-sparc \
			SunOS-*-* DragonFly-*-i386

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly"
. if (${MACHINE_ARCH} == "i386")
DEPENDS+=	suse_x11>=6.1:../../emulators/${SUSE_DIR_PREFIX}_x11
DISTNAME=	linux-ar-405
PLATFORM=	intellinux
WRKSRC=		${WRKDIR}/ILINXR.install
. elif (${MACHINE_ARCH} == "alpha")
.  if !exists(/emul/osf1/sbin/loader)
PKG_FAIL_REASON+=	'${PKGNAME} requires Digital UNIX libraries - see compat_osf1(8)'
.  endif
DISTNAME=	fdec-rs-405
PLATFORM=       alphaosf
WRKSRC=		${WRKDIR}/AOSFRS.install
. elif (${MACHINE_ARCH} == "sparc")
.  if !exists(/emul/svr4/usr/lib/ld.so)
PKG_FAIL_REASON+=	'${PKGNAME} requires Solaris libraries - see compat_svr4(8)'
.  endif
DISTNAME=	sunsparc-rs-405
WRKSRC=		${WRKDIR}/SSOLRS.install
PLATFORM=	sparcsolaris
. endif
.include "../../emulators/suse_linux/Makefile.application"
.elif ${OPSYS} == "SunOS"
. if (${MACHINE_ARCH} == "i386")
DISTNAME=	sunx86-ar-405
WRKSRC=		${WRKDIR}/SS86RS.install
PLATFORM=	intelsolaris
. else
DISTNAME=	sunsparc-rs-405
WRKSRC=		${WRKDIR}/SSOLRS.install
PLATFORM=	sparcsolaris
. endif # i86pc

# Solaris sparc + x86:
PREPEND_PATH+=	/bin		# for "ed"
post-patch:
	${CHMOD} -R o+rwx ${WRKSRC}
.endif # SunOS

PLIST_SUBST+=	PLATFORM=${PLATFORM:Q}

NS_PLUGINS_DIR=	${PREFIX}/lib/netscape/plugins

BIN_PATCH=	${PATCH} --quiet ${_PATCH_BACKUP_ARG} .orig

INSTALLATION_DIRS=	bin

do-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/Acrobat4
	@( ${ECHO} accept ) | PAGER=${CAT} ReadInstallDir=${PREFIX}/Acrobat4 ${WRKSRC}/INSTALL

post-install:
	@cd ${PREFIX}/Acrobat4/bin && \
	  ${BIN_PATCH} <${FILESDIR}/acroread.diff && \
	  ${INSTALL_SCRIPT} ${PREFIX}/Acrobat4/bin/acroread \
	     ${PREFIX}/bin/acroread4 && ${RM} -f acroread.orig
	${CHMOD} +x ${PREFIX}/bin/acroread4
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${PREFIX}/Acrobat4/Browsers/${PLATFORM}/nppdf.so \
		${NS_PLUGINS_DIR}
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat4/Reader/License.pdf"
.if ((${PLATFORM} == "sparcsolaris") || (${PLATFORM} == "intelsolaris"))
	@cd ${PREFIX}/Acrobat4/Reader/${PLATFORM}/lib && \
	for LIB in AGM.so.3 CoolType.so.1 ICC.so.1 readcore.so.4; do \
	  ${RM} -f lib$${LIB} && \
	  ${LN} -s lib$${LIB}.* lib$${LIB}; \
	done
.endif

.include "../../mk/bsd.pkg.mk"

bla:
	@echo OPSYS=${OPSYS}
	@echo MACHINE_ARCH=${MACHINE_ARCH}
	@echo PLATFORM=${PLATFORM}
