# $NetBSD: Makefile,v 1.7 2000/05/03 17:03:20 rh Exp $
#

DISTNAME=		so51a_lnx_${LANGNO}
PKGNAME=		staroffice-${LANGUAGE}-5.1a
WRKSRC=			${WRKDIR}/so51inst/office51
CATEGORIES=		misc
MASTER_SITES=		${DOWNLOAD_SITE}
EXTRACT_SUFX=		.tar

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.sun.com/staroffice/

CONFLICTS=		staroffice-*
DEPENDS+=		unzip-*:../../archivers/unzip
DEPENDS+=		suse_linux>=6.1:../../emulators/suse_linux

NO_CDROM=		"Redistribution not permitted"
MIRROR_DISTFILE=	NO

ONLY_FOR_PLATFORM=	NetBSD-1.4?-i386
PATCH_FUZZ_FACTOR=	-F1
IS_INTERACTIVE=		YES
NO_BUILD=		YES

DECOMPRESS_CMD=		${CAT}

.include "../../mk/bsd.prefs.mk"

LANGUAGE?=		en
COUNTRY?=		United States
DOWNLOAD_SITE?=		http://jsecom11b.sun.com/
BATCH_FETCH?=		NO

.if ${BATCH_FETCH} == "NO"
FETCH_INTERACTIVE=	1
.endif

.if ${LANGUAGE} == "de"
LANGNO=			49
LANGSUB=		51AA999B
#.elif ${LANGUAGE} == "fr"
#LANGNO=			33
#LANGSUB=		51AA999A
#.elif ${LANGUAGE} == "it"
#LANGNO=			39
#LANGSUB=		51AA999E
#.elif ${LANGUAGE} == "es"
#LANGNO=			34
#LANGSUB=		51AA999F
#.elif ${LANGUAGE} == "sv"
#LANGNO=			46
#LANGSUB=		51AA999G
#.elif ${LANGUAGE} == "nl"
#LANGNO=			31
#LANGSUB=		51AA999M
#.elif ${LANGUAGE} == "pt"
#LANGNO=			03
#LANGSUB=		51AA999N
.else
LANGNO=			01
LANGSUB=		51AA9999
.endif

PLIST_SUBST+=		LANGNO=${LANGNO}
PLIST_SRC=		${WRKDIR}/PLIST
MESSAGE_FILE=		${WRKDIR}/MESSAGE
INSTALL_FILE=		${WRKDIR}/INSTALL

do-fetch:
	@${MKDIR} ${WRKDIR}
.for file in automate.sh send.agree send.conf send.ord send.resp \
	     send.submit sendreg.sh
	@${CP} ${FILESDIR}/${file} ${WRKDIR}
.endfor
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		cd ${WRKDIR} && \
		${SETENV} COUNTRY="${COUNTRY}" \
			  LANGSUB=${LANGSUB} LANGNO=${LANGNO} \
			  DISTDIR=${DISTDIR} \
			  DISTFILE=${DISTNAME}${EXTRACT_SUFX} \
			  INTERACTIVE=${FETCH_INTERACTIVE} \
			  HOMEPAGE=${HOMEPAGE} SITE=${DOWNLOAD_SITE} \
		./automate.sh ; \
	fi

do-configure:
.for file in setup.ins
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	    <${WRKSRC}/${file} >${WRKSRC}/${file}.new
	${MV} ${WRKSRC}/${file}.new ${WRKSRC}/${file}
.endfor

pre-install:
	@if [ "$$DISPLAY" = "" ]; then \
		${ECHO} "${DISTNAME} needs to be installed under X11."; \
		exit 1; \
	fi
	@if [ "`/sbin/mount | ${GREP} 'on /proc' | ${CUT} -d ' ' -f 5`" != "procfs" ]; then \
		${ECHO} "${DISTNAME} needs procfs to be mounted on /proc."; \
		exit 1; \
	fi
	@${CAT} ${PKGDIR}/PLIST.${LANGNO} ${PKGDIR}/PLIST >${PLIST_SRC}

do-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "-------------------------------------------------------"
	@${ECHO_MSG} " Now running the StarOffice system installation script. "
	@${ECHO_MSG} ""
	@${ECHO_MSG} " Simply hit <RETURN> on every requester.  Please do    "
	@${ECHO_MSG} " _not_ try to change any setup parameters at this time "
	@${ECHO_MSG} " (you can do that later during user installation).     "
	@${ECHO_MSG} ""
	@${ECHO_MSG} " If you do make modifications, automatic package       "
	@${ECHO_MSG} " deinstallation may fail and you will have to remove   "
	@${ECHO_MSG} " ${PREFIX}/Office51 by hand after running 'pkg_delete' "
	@${ECHO_MSG} "-------------------------------------------------------"
	@${ECHO_MSG} ""
	@${INSTALL_DATA_DIR} ${PREFIX}/Office51
	@cd ${WRKSRC} && ${SETENV} LD_LIBRARY_PATH=${WRKSRC} \
	${WRKSRC}/setup.bin /net

post-install:
.for file in instdb soffice
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' < ${FILESDIR}/${file}.patch | \
	${PATCH} -s -N -d ${PREFIX}/Office51
.endfor
.for file in sosetup soffice
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' < ${FILESDIR}/${file} \
		>${WRKDIR}/${file}
	${INSTALL_SCRIPT} ${WRKDIR}/${file} ${PREFIX}/bin
.endfor
.for file in MESSAGE INSTALL
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' < ${PKGDIR}/${file} \
		>${WRKDIR}/${file}
.endfor

.include "../../mk/bsd.pkg.mk"
