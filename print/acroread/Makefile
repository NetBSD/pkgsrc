# $NetBSD: Makefile,v 1.14 2000/04/18 01:46:16 dmcmahill Exp $
# FreeBSD Id: Makefile,v 1.13 1999/04/08 07:49:18 dima Exp $

PKGNAME=	acroread-4.05
CATEGORIES=	print
MASTER_SITES=	ftp://ftp-pac.adobe.com/pub/adobe/acrobatreader/unix/4.x/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.adobe.com/prodindex/acrobat/readstep.html

IS_INTERACTIVE=	YES
RESTRICTED=	"Original installer required to redistribute."
NO_CDROM=	${RESTRICTED}

NO_BUILD=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.if (${MACHINE_ARCH} == "i386")
DEPENDS=	suse_linux>=6.1:../../emulators/suse_linux
DISTNAME=	linux-ar-405
PLATFORM=	intellinux
WRKSRC=		${WRKDIR}/ILINXR.install
.elif (${MACHINE_ARCH} == "alpha")
.if !exists(/emul/osf1/sbin/loader)
IGNORE=	'requires Digital UNIX libraries - see compat_osf1(8)'
.endif
DISTNAME=	fdec-rs-405
PLATFORM=       alphaosf
WRKSRC=		${WRKDIR}/AOSFRS.install
.elif (${MACHINE_ARCH} == "sparc")
.if !exists(/emul/svr4/usr/lib/ld.so)
IGNORE=		'requires Solaris libraries - see compat_svr4(8)'
.endif
DISTNAME=	sunsparc-rs-405
WRKSRC=		${WRKDIR}/SSOLRS.install
PLATFORM=	sparcsolaris
.else
DISTNAME=	${PKGNAME}
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

do-install:
	@${MKDIR} ${PREFIX}/Acrobat4
	@ReadInstallDir=${PREFIX}/Acrobat4 ${WRKSRC}/INSTALL

post-install:
	@cd ${PREFIX}/Acrobat4/bin && \
	  ${PATCH} --quiet < ${FILESDIR}/acroread.diff && \
	  ${INSTALL_SCRIPT} ${PREFIX}/Acrobat4/bin/acroread \
	     ${PREFIX}/bin/acroread && ${RM} acroread.orig
	${CHMOD} +x ${PREFIX}/bin/acroread
	${LN} -f ${PREFIX}/bin/acroread ${PREFIX}/bin/acroread4
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${PREFIX}/Acrobat4/Browsers/${PLATFORM}/nppdf.so \
		${NS_PLUGINS_DIR}
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat4/Reader/License.pdf"

.include "../../mk/bsd.pkg.mk"
