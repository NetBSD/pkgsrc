# $NetBSD: Makefile,v 1.7 2009/06/04 08:32:46 obache Exp $

DISTNAME=	acroread8	# overridden below
PKGNAME=	acroread8-8.1.5
CATEGORIES=	print
MASTER_SITES=	http://ardownload.adobe.com/pub/adobe/reader/unix/8.x/8.1.5/enu/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.adobe.com/products/acrobat/readstep2.html
COMMENT=	View, distribute and print PDF documents
LICENSE=	adobe-acrobat-license

RESTRICTED=		Original installer required to redistribute.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	acroread-5.*
# conflict with acroread5 due to bin/acroread
# maybe should do ALTERNATIVES?
CONFLICTS+=	acroread5-5.*
CONFLICTS+=	acroread7-7.*

WRKSRC=			${WRKDIR}/AdobeReader
BUILD_DIRS=		# empty

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	compat cups gtk2 locale
EMUL_REQD=		suse>=10.0

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
DISTNAME=	AdobeReader_enu-8.1.5-1.i486
PLATFORM=	intellinux
.else
PLATFORM=	unknown
.endif

PLIST_SUBST+=	PLATFORM=${PLATFORM:Q}

BIN_PATCH=	${PATCH} --quiet ${_PATCH_BACKUP_ARG} .orig

# Additional directories to search for fonts
BUILD_DEFS+=		ACROREAD_FONTPATH
ACROREAD_FONTPATH?=	${PREFIX}/lib/X11/fonts/TTF

INSTALLATION_DIRS=	Acrobat8 bin

do-install:
	( ${ECHO} n; ${ECHO} n ) | InstallDir=${DESTDIR}${PREFIX}/Acrobat8 ${WRKSRC}/INSTALL

post-install:
	cd ${DESTDIR}${PREFIX}/Acrobat8/Adobe/Reader8/bin && \
	  ${BIN_PATCH} <${FILESDIR}/acroread.diff && \
	  ${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    -e 's|@ACROREAD_FONTPATH@|${ACROREAD_FONTPATH}|' \
		<acroread >acroread.tmp && \
	  ${MV} acroread.tmp acroread && \
	  ${RM} -f acroread.orig acroread.tmp
	${LN} -sf ${DESTDIR}${PREFIX}/Acrobat8/Adobe/Reader8/bin/acroread \
	     ${DESTDIR}${PREFIX}/bin/acroread8
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/acroread8
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${DESTDIR}${PREFIX}/Acrobat8/Reader/Legal/ENU/License.html"
	${LN} -sf acroread8 ${DESTDIR}${PREFIX}/bin/acroread

.include "../../mk/bsd.pkg.mk"
