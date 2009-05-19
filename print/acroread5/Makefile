# $NetBSD: Makefile,v 1.38 2009/05/19 08:59:30 wiz Exp $

DISTNAME=	acroread5	# overridden below
PKGNAME=	acroread5-5.10
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	http://ardownload.adobe.com/pub/adobe/acrobatreader/unix/5.x/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.adobe.com/products/acrobat/readstep2.html
COMMENT=	View, distribute and print PDF documents
LICENSE=		adobe-acrobat-license

RESTRICTED=		Original installer required to redistribute.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

CONFLICTS+=	acroread-5.*
# conflict with acroread7 due to bin/acroread
CONFLICTS+=	acroread-7.*
CONFLICTS+=	acroread7-7.*

WRKSRC=			${WRKDIR}/installers
BUILD_DIRS=		# empty

EMUL_PLATFORMS=		linux-i386
EMUL_PLATFORMS+=	solaris-sparc
EMUL_MODULES.linux=	x11

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
DISTNAME=	linux-5010
PLATFORM=	intellinux
.elif ${EMUL_PLATFORM} == "solaris-sparc"
DISTNAME=	solaris-5010
PLATFORM=	sparcsolaris
.else
PLATFORM=	unknown
.endif

PLIST_SUBST+=	PLATFORM=${PLATFORM:Q}

BIN_PATCH=	${PATCH} --quiet ${_PATCH_BACKUP_ARG} .orig

INSTALLATION_DIRS=	bin

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
	${LN} -sf ${PREFIX}/bin/acroread5 ${PREFIX}/bin/acroread

.include "../../mk/bsd.pkg.mk"
