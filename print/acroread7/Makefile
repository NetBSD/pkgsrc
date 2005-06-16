# $NetBSD: Makefile,v 1.2 2005/06/16 23:56:15 kristerw Exp $

DISTNAME=	acroread7	# Overridden below
PKGNAME=	acroread7-7.0
CATEGORIES=	print
MASTER_SITES=	http://ardownload.adobe.com/pub/adobe/reader/unix/7x/7.0/enu/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.adobe.com/prodindex/acrobat/readstep.html
COMMENT=	View, distribute and print PDF documents

CONFLICTS+=	acroread-5.*
# conflict with acroread5 due to bin/acroread
# maybe should do ALTERNATIVES?
CONFLICTS+=	acroread5-5.*

RESTRICTED=	"Original installer required to redistribute."
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
LICENSE=	adobe-acrobat-license

WRKSRC=		${WRKDIR}/AdobeReader
CHECK_SHLIBS=	NO
NO_BUILD=	YES
SHLIB_HANDLING=	NO

.include "../../mk/bsd.prefs.mk"

ONLY_FOR_PLATFORM=	*-*-i386

# Default (overridden below)
PLATFORM=	unknown

.if ${OPSYS} == "NetBSD"
. if (${MACHINE_ARCH} == "i386")
DEPENDS=	suse_gtk2>=9.1:../../emulators/suse91_gtk2
DEPENDS+=	suse_locale>=9.1:../../emulators/suse91_locale
DISTNAME=	AdbeRdr70_linux_enu
PLATFORM=	intellinux
.endif
.elif ${OPSYS} == "Linux"
DISTNAME=	AdbeRdr70_linux_enu
PLATFORM=	intellinux
.endif

PLIST_SUBST+=	PLATFORM=${PLATFORM}

BIN_PATCH=	${PATCH} --quiet ${_PATCH_BACKUP_ARG} .orig

# Additional directories to search for fonts
BUILD_DEFS+=	ACROREAD_FONTPATH
ACROREAD_FONTPATH?= ${PREFIX}/lib/X11/fonts/TTF

do-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/Acrobat7
	@( ${ECHO} accept ) | PAGER=${CAT} InstallDir=${PREFIX}/Acrobat7 ${WRKSRC}/INSTALL

post-install:
	@cd ${PREFIX}/Acrobat7/bin && \
	  ${BIN_PATCH} <${FILESDIR}/acroread.diff && \
	  ${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    -e 's|@ACROREAD_FONTPATH@|${ACROREAD_FONTPATH}|' \
		<acroread >acroread.tmp && \
	  ${MV} acroread.tmp acroread && \
	  ${INSTALL_SCRIPT} ${PREFIX}/Acrobat7/bin/acroread \
	     ${PREFIX}/bin/acroread7 && ${RM} -f acroread.orig acroread.tmp
	${CHMOD} +x ${PREFIX}/bin/acroread7
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat7/Reader/Legal/ENU/License.html"
	${LN} -sf ${PREFIX}/bin/acroread7 ${PREFIX}/bin/acroread
	${RM} ${PREFIX}/Acrobat7/Reader/${PLATFORM}/plug_ins/PPKLite.api

# do not include the linux stuff if we are, for example, on a Solaris box
. if (${MACHINE_ARCH} == "i386")
.include "../../emulators/suse_linux/Makefile.application"
.endif
.include "../../mk/bsd.pkg.mk"
