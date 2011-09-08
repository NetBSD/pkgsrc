# $NetBSD: Makefile,v 1.43 2011/09/08 19:29:35 cheusov Exp $

DISTNAME=	acroread5	# overridden below
PKGNAME=	acroread5-5.10
PKGREVISION=	5
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

PKG_DESTDIR_SUPPORT=	user-destdir

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

INSTALLATION_DIRS=	bin ${PREFIX}/Acrobat5

do-install:
	@( ${ECHO} accept ) | PAGER=${CAT} ReadInstallDir=${DESTDIR}${PREFIX}/Acrobat5 ${WRKSRC}/INSTALL
	@cd ${DESTDIR}${PREFIX}/Acrobat5/bin && \
	  ${BIN_PATCH} <${FILESDIR}/acroread.diff && \
	  ${INSTALL_SCRIPT} ${DESTDIR}${PREFIX}/Acrobat5/bin/acroread \
	     ${DESTDIR}${PREFIX}/bin/acroread5 && ${RM} -f acroread.orig
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/acroread5
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat5/Reader/license.txt"

.if !empty(DESTDIR)
SUBST_CLASSES+=		rmdestdir
SUBST_STAGE.rmdestdir=	post-install
SUBST_FILES.rmdestdir=	${DESTDIR}${PREFIX}/bin/acroread5
SUBST_FILES.rmdestdir=	${DESTDIR}${PREFIX}/Acrobat5/bin/acroread
SUBST_SED.rmdestdir=	-e 's,${DESTDIR},,g'
.endif

.include "../../mk/bsd.pkg.mk"
