# $NetBSD: Makefile,v 1.4.2.1 2012/04/15 13:21:39 tron Exp $

DISTNAME=	acroread9	# overridden below
PKGNAME=	acroread9-9.5.1
CATEGORIES=	print
MASTER_SITES=	http://ardownload.adobe.com/pub/adobe/reader/unix/9.x/${PKGVERSION_NOREV}/enu/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.adobe.com/products/acrobat/readstep2.html
COMMENT=	View, distribute and print PDF documents
LICENSE=	adobe-acrobat-license

RESTRICTED=		Original installer required to redistribute.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/AdobeReader
BUILD_DIRS=		# empty

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	compat cups gtk2 locale xml2
EMUL_REQD=		suse>=10.0

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
DISTNAME=	AdbeRdr${PKGVERSION_NOREV}-1_i486linux_enu
EXTRACT_SUFX=	.tar.bz2
PLATFORM=	intellinux
PLIST_SRC=	PLIST
PLATFORM=	unknown
.endif

PLIST_SUBST+=	PLATFORM=${PLATFORM:Q}

BIN_PATCH=	${PATCH} --quiet ${_PATCH_BACKUP_ARG} .orig

# Additional directories to search for fonts
BUILD_DEFS+=		ACROREAD_FONTPATH
ACROREAD_FONTPATH?=	${PREFIX}/lib/X11/fonts/TTF

INSTALLATION_DIRS=	Acrobat9 bin ${PKGMANDIR}/man1

do-install:
	set -e; ( ${ECHO} n; ${ECHO} n ) | InstallDir=${DESTDIR}${PREFIX}/Acrobat9 ${WRKSRC}/INSTALL

post-install:
	set -e;
	cd ${DESTDIR}${PREFIX}/Acrobat9/Adobe/Reader9/Reader/GlobalPrefs && \
	  ${BIN_PATCH} <${FILESDIR}/reader_prefs.diff && \
	  ${RM} -f reader_prefs.orig
	cd ${DESTDIR}${PREFIX}/Acrobat9/Adobe/Reader9/bin && \
	  ${BIN_PATCH} <${FILESDIR}/acroread.diff && \
	  ${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    -e 's|@ACROREAD_FONTPATH@|${ACROREAD_FONTPATH:Q}|' \
	    -e 's|@EMULDIR@|${EMULDIR}|' \
		<acroread >acroread.tmp && \
	  ${MV} acroread.tmp acroread && \
	  ${RM} -f acroread.orig acroread.tmp
	${LN} -sf ${DESTDIR}${PREFIX}/Acrobat9/Adobe/Reader9/bin/acroread \
	     ${DESTDIR}${PREFIX}/bin/acroread9
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/acroread9
	${MV} ${DESTDIR}${PREFIX}/Acrobat9/Adobe/Reader9/Resource/Shell/acroread.1 \
	  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/acroread9.1
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${DESTDIR}${PREFIX}/Acrobat9/Reader/Legal/ENU/License.html"

.include "../../mk/bsd.pkg.mk"
