# $NetBSD: Makefile,v 1.30 2002/07/02 11:40:16 agc Exp $

PKGNAME=	acroread-4.05
CATEGORIES=	print
MASTER_SITES=	ftp://ftp-pac.adobe.com/pub/adobe/acrobatreader/unix/4.x/

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

.if ${OPSYS} == "NetBSD"
.if (${MACHINE_ARCH} == "i386")
DEPENDS=	suse_x11>=6.1:../../emulators/${SUSE_DIR_PREFIX}_x11
DISTNAME=	linux-ar-405
PLATFORM=	intellinux
WRKSRC=		${WRKDIR}/ILINXR.install
.elif (${MACHINE_ARCH} == "alpha")
.if !exists(/emul/osf1/sbin/loader)
IGNORE=	'${PKGNAME} requires Digital UNIX libraries - see compat_osf1(8)'
.endif
DISTNAME=	fdec-rs-405
PLATFORM=       alphaosf
WRKSRC=		${WRKDIR}/AOSFRS.install
.elif (${MACHINE_ARCH} == "sparc")
.if !exists(/emul/svr4/usr/lib/ld.so)
IGNORE=		'${PKGNAME} requires Solaris libraries - see compat_svr4(8)'
.endif
DISTNAME=	sunsparc-rs-405
WRKSRC=		${WRKDIR}/SSOLRS.install
PLATFORM=	sparcsolaris
.else
DISTNAME=	${PKGNAME}
PLATFORM=	unknown
.endif
ONLY_FOR_PLATFORM=	*-*-i386 *-1.4[L-Z]-sparc *-1.[5-9]*-sparc *-[2-9]*-sparc
# *-*-alpha 
.elif ${OPSYS} == "SunOS"
DISTNAME=	sunsparc-rs-405
WRKSRC=		${WRKDIR}/SSOLRS.install
PLATFORM=	sparcsolaris

post-patch:
	${CHMOD} -R o+rwx ${WRKSRC}
.endif

PLIST_SUBST+=	PLATFORM=${PLATFORM}

PLIST_SRC=	${PKGDIR}/PLIST.pre \
		${PKGDIR}/PLIST.${MACHINE_ARCH} \
		${PKGDIR}/PLIST.post

NS_PLUGINS_DIR=	${PREFIX}/lib/netscape/plugins

BIN_PATCH=	${PATCH} --quiet ${_PATCH_BACKUP_ARG} .orig

do-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/Acrobat4
	@( ${ECHO} accept ) | PAGER=${CAT} ReadInstallDir=${PREFIX}/Acrobat4 ${WRKSRC}/INSTALL

post-install:
	@cd ${PREFIX}/Acrobat4/bin && \
	  ${BIN_PATCH} <${FILESDIR}/acroread.diff && \
	  ${INSTALL_SCRIPT} ${PREFIX}/Acrobat4/bin/acroread \
	     ${PREFIX}/bin/acroread && ${RM} -f acroread.orig
	${CHMOD} +x ${PREFIX}/bin/acroread
	${LN} -f ${PREFIX}/bin/acroread ${PREFIX}/bin/acroread4
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${PREFIX}/Acrobat4/Browsers/${PLATFORM}/nppdf.so \
		${NS_PLUGINS_DIR}
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat4/Reader/License.pdf"
.if (${PLATFORM} == "sparcsolaris")
	@cd ${PREFIX}/Acrobat4/Reader/${PLATFORM}/lib && \
	for LIB in AGM.so.3 CoolType.so.1 ICC.so.1 readcore.so.4; do \
	  ${RM} -f lib$${LIB} && \
	  ${LN} -s lib$${LIB}.* lib$${LIB}; \
	done
.endif

.include "../../emulators/suse_linux/Makefile.application"
