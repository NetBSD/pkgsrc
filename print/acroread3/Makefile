# $NetBSD: Makefile,v 1.1.1.1 2000/01/14 15:19:28 dmcmahill Exp $

PKGNAME=	acroread-3.01
CATEGORIES=	print
MASTER_SITES=	ftp://ftp-pac.adobe.com/pub/adobe/acrobatreader/unix/3.x/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.adobe.com/prodindex/acrobat/readstep.html

IS_INTERACTIVE=	YES
RESTRICTED=	"Original installer required to redistribute."
NO_CDROM=	${RESTRICTED}

NO_BUILD=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.if (${MACHINE_ARCH} == "i386")
DEPENDS=	suse_linux-6.1p1:../../emulators/suse_linux
DISTNAME=	acroread_linux_301
PLATFORM=	intellinux
#.elif (${MACHINE_ARCH} == "alpha")
#.if !exists(/emul/osf1/sbin/loader)
#IGNORE=	requires Digital UNIX libraries - see compat_osf1(8)
#.endif
#DISTNAME=	acroread_osf_301
#PLATFORM=	osf
.elif (${MACHINE_ARCH} == "sparc")
.if !exists(/emul/sunos/usr/lib/ld.so)
IGNORE=	requires SunOS libraries - see compat_sunos(8)
.endif
DISTNAME=	acroread_sunos_301
PLATFORM=	sparcsun
.else
DISTNAME=	${PKGNAME}
.endif
ONLY_FOR_PLATFORM=	*-*-i386 *-*-sparc
# *-*-alpha 
.elif ${OPSYS} == "SunOS"
DISTNAME=	acroread_solaris_301
PLATFORM=	sparcsolaris
post-patch:
	${CHMOD} -R o+rwx ${WRKSRC}
.else
DISTNAME=	${PKGNAME}
.endif

WRKSRC=		${WRKDIR}
PLIST_SRC=	${PKGDIR}/PLIST.pre \
		${PKGDIR}/PLIST.${LOWER_OPSYS}-${MACHINE_ARCH} \
		${PKGDIR}/PLIST.post
PLIST_SUBST+=	PLATFORM=${PLATFORM}

pre-install:
#	${SED} -e 's|@PLATFORM@|${PLATFORM}|g' ${PKGDIR}/PLIST > ${PLIST_SRC}

do-install:
	@${MKDIR} ${PREFIX}/Acrobat3
	@ReadInstallDir=${PREFIX}/Acrobat3 ${WRKSRC}/INSTALL

post-install:
	@cd ${PREFIX}/Acrobat3/bin && \
	  ${PATCH} --quiet < ${FILESDIR}/acroread.diff && \
	  ${INSTALL_SCRIPT} ${PREFIX}/Acrobat3/bin/acroread \
	     ${PREFIX}/bin/acroread3 && ${RM} acroread.orig
	@chmod +x ${PREFIX}/bin/acroread3
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat3/Reader/License.pdf"

.include "../../mk/bsd.pkg.mk"
