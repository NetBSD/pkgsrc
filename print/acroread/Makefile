# $NetBSD: Makefile,v 1.3 1999/06/17 01:04:29 sakamoto Exp $
# FreeBSD Id: Makefile,v 1.13 1999/04/08 07:49:18 dima Exp $

PKGNAME=	acroread-4.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp-pac.adobe.com/pub/adobe/acrobatreader/unix/4.x/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.adobe.com/prodindex/acrobat/readstep.html

IS_INTERACTIVE=	YES
RESTRICTED=	"Original installer required to redistribute."

NO_BUILD=	YES

.if (${MACHINE_ARCH} == "i386")
.if !exists(/emul/linux/lib/ld-linux.so.2)
IGNORE=You must have Linux libraries installed - see compat_linux(8)
.endif
DISTNAME=	linux-ar-40
#.elif (${MACHINE_ARCH} == "alpha")
#.if !exists(/emul/osf1/sbin/loader)
#IGNORE=You must have Digital UNIX libraries installed - see compat_osf1(8)
#.endif
#DISTNAME=	dec-arws-40
#.elif (${MACHINE_ARCH} == "sparc")
#.if !exists(/emul/sunos/usr/lib/ld.so)
#IGNORE=You must have SunOS libraries installed - see compat_sunos(8)
#.endif
#DISTNAME=	sunsparc-arws-40
.else
DISTNAME=	${PKGNAME}
.endif

ONLY_FOR_PLATFORM=	*-*-i386
# *-*-alpha *-*-sparc

WRKSRC=		${WRKDIR}/ILINXR.install

do-install:
	@${MKDIR} ${PREFIX}/Acrobat4
	@ReadInstallDir=${PREFIX}/Acrobat4 ${WRKSRC}/INSTALL

post-install:
	@cd ${PREFIX}/Acrobat4/bin && \
	  ${PATCH} --quiet < ${FILESDIR}/acroread.diff && \
	  ${INSTALL_SCRIPT} ${PREFIX}/Acrobat4/bin/acroread \
	     ${PREFIX}/bin/acroread4 && ${RM} acroread.orig
	@chmod +x ${PREFIX}/bin/acroread4
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat4/Reader/License.pdf"

.include "../../mk/bsd.pkg.mk"
