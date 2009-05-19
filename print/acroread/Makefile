# $NetBSD: Makefile,v 1.55 2009/05/19 08:59:30 wiz Exp $

DISTNAME=	acroread	# overridden below
PKGNAME=	acroread-4.05
PKGREVISION=	5
CATEGORIES=	print
MASTER_SITES=	ftp://ftp-pac.adobe.com/pub/adobe/acrobatreader/unix/4.x/ \
		http://download.adobe.com/pub/adobe/acrobatreader/unix/4.x/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.adobe.com/products/acrobat/readstep2.html
COMMENT=	View, distribute and print PDF documents
LICENSE=	adobe-acrobat-license

RESTRICTED=		Original installer required to redistribute.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

BUILD_DIRS=		# empty

EMUL_PLATFORMS=		linux-i386
EMUL_PLATFORMS+=	osf1-alpha
EMUL_PLATFORMS+=	solaris-i386 solaris-sparc
EMUL_MODULES.linux=	x11

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
DISTNAME=	linux-ar-405
PLATFORM=	intellinux
WRKSRC=		${WRKDIR}/ILINXR.install
.elif ${EMUL_PLATFORM} == "osf1-alpha"
DISTNAME=	fdec-rs-405
PLATFORM=	alphaosf
WRKSRC=		${WRKDIR}/AOSFRS.install
.elif ${EMUL_PLATFORM} == "solaris-i386"
DISTNAME=	sunx86-ar-405
WRKSRC=		${WRKDIR}/SS86RS.install
PLATFORM=	intelsolaris
.elif ${EMUL_PLATFORM} == "solaris-sparc"
DISTNAME=	sunsparc-rs-405
WRKSRC=		${WRKDIR}/SSOLRS.install
PLATFORM=	sparcsolaris
PREPEND_PATH+=	/bin		# for "ed"

post-patch:
	${CHMOD} -R o+rwx ${WRKSRC}
.else
PLATFORM=	unknown
.endif

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
