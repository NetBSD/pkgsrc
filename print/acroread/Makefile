# $NetBSD: Makefile,v 1.2 1999/06/16 11:08:30 sakamoto Exp $
# FreeBSD Id: Makefile,v 1.13 1999/04/08 07:49:18 dima Exp $

DISTNAME=	linux-ar-40
PKGNAME=	acroread-4.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp-pac.adobe.com/pub/adobe/acrobatreader/unix/4.x/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.adobe.com/prodindex/acrobat/readstep.html

NO_BUILD=	yes

.if (${MACHINE_ARCH} == "i386")
.if !exists(/emul/linux/lib/ld-linux.so.2)
IGNORE=You must have Linux libraries installed - see compat_linux(8)
.endif
.endif
ONLY_FOR_PLATFORM=	*-*-i386

WRKSRC=		${WRKDIR}/ILINXR.install
MESSAGE_SRC=	${PKGDIR}/MESSAGE
MESSAGE_FILE=	${WRKDIR}/.MESSAGE

do-install:
	@${MKDIR} ${PREFIX}/Acrobat4
	@ReadInstallDir=${PREFIX}/Acrobat4 ${WRKSRC}/INSTALL

post-install:
	@${SED} -e 's|$${PREFIX}|${PREFIX}|' ${MESSAGE_SRC} > ${MESSAGE_FILE}
	@cd ${PREFIX}/Acrobat4/bin && \
	  ${PATCH} --quiet < ${FILESDIR}/acroread.diff && \
	  ${INSTALL_SCRIPT} ${PREFIX}/Acrobat4/bin/acroread \
	     ${PREFIX}/bin/acroread4 && ${RM} acroread.orig
	@chmod +x ${PREFIX}/bin/acroread4
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat4/Reader/License.pdf"

.include "../../mk/bsd.pkg.mk"
