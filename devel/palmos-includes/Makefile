# $NetBSD: Makefile,v 1.8 2004/04/06 19:25:02 dillo Exp $
#

DISTNAME=       sdk50-win
PKGNAME=	palmos-includes-5.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.palmos.com/dev/tools/sdk/
DISTFILES=	sdk50-win.zip
DISTFILES+=	sdk40-core.tar.gz sdk40upd1.tar.gz
DISTFILES+=	sdk35.tar.gz sdk35-update1.tar.gz
DISTFILES+=	sdk31a1.zip

MAINTAINER=	tech-pkg@giga.or.at
HOMEPAGE=	http://www.palmos.com/dev/tools/gcc/index.html
COMMENT=	Palm OS include files

BUILD_DEPENDS+=	wget-[0-9]*:../../net/wget
DEPENDS+=	prc-tools>=2.2:../../devel/prc-tools

SITES_sdk50-win.zip=http://www.palmos.com/cgi-bin/sdk50.cgi
SITES_sdk40-core.tar.gz=http://www.palmos.com/cgi-bin/sdk40.cgi
SITES_sdk40upd1.tar.gz=http://www.palmos.com/cgi-bin/sdk40.cgi
SITES_sdk35.tar.gz=http://www.palmos.com/cgi-bin/sdk35.cgi
SITES_sdk35-update1.tar.gz=http://www.palmos.com/cgi-bin/sdk35.cgi

NO_CONFIGURE=	YES
NO_BUILD=	YES
EXTRACT_CMD_OPTS.zip=	-aqo

RESTRICTED=	Redistribution not permitted
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

LICENSE=	palmos-sdk-license
PLIST_SUBST+=	DEFAULT_SDK="${PALMOS_DEFAULT_SDK}"

PALMDEV=	${PREFIX}/share/palmdev
DOCDIR=		${PREFIX}/share/doc/palmdev
SDK50=		${WRKDIR}/Palm_OS_5_SDK_dr12
SDK40=		${WRKDIR}
SDK401=		${WRKDIR}/PalmOS-4.0-SDK-Update-1/PalmOS-Unix
SDK35=		${WRKDIR}/Palm\ OS\ 3.5\ Support
SDK31=		${WRKDIR}/Palm\ OS\ 3.1\ Support

.include "../../mk/bsd.prefs.mk"

PALMOS_DEFAULT_SDK?=	4.0.1

pre-fetch: install-depends
.  for fetchfile in ${DISTFILES}
.    if defined(SITES_${fetchfile})
	@if [ ! -f ${DISTDIR}/${fetchfile} ]; then			\
		${ECHO} "=> ${fetchfile} doesn't seem to exist on this system.";\
		${ECHO} '=> Attempting to fetch ${fetchfile} from'	\
				'${SITES_${fetchfile}}';		\
		cd ${DISTDIR} && 					\
		    wget --header 'Referer: ${SITES_${fetchfile}}'	\
			${SITES_${fetchfile}}/${fetchfile};		\
	fi
.    endif
.  endfor

EXTRACT_NORMAL=sdk40-core.tar.gz sdk40upd1.tar.gz sdk35.tar.gz sdk35-update1.tar.gz sdk31a1.zip

do-extract: ${WRKDIR}
.  for file in ${EXTRACT_NORMAL}
	@extract_file="${DISTDIR}/${file}"; export extract_file;    \
	cd ${WRKDIR}; ${EXTRACT_CMD}
.  endfor
	@extract_file="${DISTDIR}/sdk50-win.zip"; export extract_file;	\
	cd ${WRKDIR}; ${MKDIR} Palm_OS_5_SDK_dr12; cd Palm_OS_5_SDK_dr12; \
	${EXTRACT_CMD}

do-install:
	${INSTALL_DATA_DIR} ${PALMDEV}
	${INSTALL_DATA_DIR} ${DOCDIR}
	# --- 5.0 ---
	${INSTALL_DATA_DIR} ${PALMDEV}/sdk-5.0
	${INSTALL_DATA_DIR} ${PALMDEV}/sdk-5.0/include
	cd ${SDK50}/Palm\ OS\ Support/Incs \
		&& ${PAX} -rw . ${PALMDEV}/sdk-5.0/include
	${INSTALL_DATA} ${SDK50}/Palm\ OS\ 5.0\ SDK\ Readme.txt \
		${DOCDIR}/sdk-5.0-readme.txt
	# --- 4.0.1 ---
	${INSTALL_DATA_DIR} ${PALMDEV}/sdk-4.0.1
	${INSTALL_DATA_DIR} ${PALMDEV}/sdk-4.0.1/include
	${INSTALL_DATA_DIR} ${PALMDEV}/sdk-4.0.1/lib
	cd ${SDK40}/Palm\ OS\ Support/Incs \
		&& ${PAX} -rw . ${PALMDEV}/sdk-4.0.1/include
	cd ${SDK40}/Palm\ OS\ Support/GCC\ Libraries \
		&& ${PAX} -rw . ${PALMDEV}/sdk-4.0.1/lib
	cd ${SDK401}/PalmOS-Support && ${PAX} -rw . ${PALMDEV}/sdk-4.0.1
	${INSTALL_DATA} ${SDK401}/Documentation/PalmOS-4.0.1-SDK-Readme \
		${DOCDIR}/sdk-4.0.1-readme.txt
	# --- 4.0 ---
	${INSTALL_DATA_DIR} ${PALMDEV}/sdk-4.0
	${INSTALL_DATA_DIR} ${PALMDEV}/sdk-4.0/include
	${INSTALL_DATA_DIR} ${PALMDEV}/sdk-4.0/lib
	cd ${SDK40}/Palm\ OS\ Support/Incs \
		&& ${PAX} -rw . ${PALMDEV}/sdk-4.0/include
	cd ${SDK40}/Palm\ OS\ Support/GCC\ Libraries \
		&& ${PAX} -rw . ${PALMDEV}/sdk-4.0/lib
	${INSTALL_DATA} ${SDK40}/Documentation/Palm\ OS\ 4.0\ SDK\ ReadMe.txt \
		${DOCDIR}/sdk-4.0-readme.txt
	# --- 3.5 ---
	${INSTALL_DATA_DIR} ${PALMDEV}/sdk-3.5
	${INSTALL_DATA_DIR} ${PALMDEV}/sdk-3.5/include
	${INSTALL_DATA_DIR} ${PALMDEV}/sdk-3.5/lib
	cd ${SDK35}/Incs && ${PAX} -rw *.h header.gcc Core Dynamic Libraries \
				${PALMDEV}/sdk-3.5/include
	cd ${SDK35}/GCC\ Libraries && ${PAX} -rw . ${PALMDEV}/sdk-3.5/lib
	# --- 3.1 ---
	${INSTALL_DATA_DIR} ${PALMDEV}/sdk-3.1
	${INSTALL_DATA_DIR} ${PALMDEV}/sdk-3.1/include
	cd ${SDK31}/Incs && ${PAX} -rw *.h Hardware International System UI \
				${PALMDEV}/sdk-3.1/include
	${INSTALL_DATA} ${WRKDIR}/SDK31\ a1\ README.txt \
		${DOCDIR}/sdk-3.1-readme.txt
	${PREFIX}/bin/palmdev-prep --default ${PALMOS_DEFAULT_SDK}

.include "../../mk/bsd.pkg.mk"
