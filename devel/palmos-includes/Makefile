# $NetBSD: Makefile,v 1.1.1.1 2001/04/25 17:39:16 wiz Exp $
#

DISTNAME=       sdk35
PKGNAME=	palmos-includes-3.5.1
CATEGORIES=	devel
MASTER_SITES=	http://www.palmos.com/dev/tech/tools/gcc/dist/
DISTFILES=	${DISTSPECIAL} palmos-1-2-3.1-sdks-1${EXTRACT_SUFX}

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.palmos.com/dev/tech/tools/gcc/
COMMENT=	Palm OS include files

BUILD_DEPENDS+=	wget-*:../../net/wget

DISTSPECIAL=	${DISTNAME}${EXTRACT_SUFX} sdk35-update1${EXTRACT_SUFX}

NO_CONFIGURE=	YES
NO_BUILD=	YES

RESTRICTED=	Redistribution not permitted
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

LICENSE=	palmos-sdk-license

DOWNLOAD_URL=	http://www.palmos.com/dev/tech/tools/sdk35.cgi
PALMDEV=	${PREFIX}/share/palmdev
WGET=		${LOCALBASE}/bin/wget --non-verbose

.include "../../mk/bsd.prefs.mk"

PALMOS_DEFAULT_SDK?=	3.5

pre-fetch: install-depends
	for f in ${DISTSPECIAL}; \
	do \
	    if [ ! -f ${DISTDIR}/$$f ]; \
	    then \
	    	cd ${DISTDIR} && \
		    ${WGET} --header 'Referer: ${DOWNLOAD_URL}' \
			${DOWNLOAD_URL}/$$f; \
	    fi; \
	done

do-install:
	${INSTALL_DATA_DIR} ${PALMDEV}/sdk-1
	cd ${WRKDIR}/sdk-1 && ${PAX} -rw include ${PALMDEV}/sdk-1
	${INSTALL_DATA_DIR} ${PALMDEV}/sdk-2
	cd ${WRKDIR}/sdk-2 && ${PAX} -rw include ${PALMDEV}/sdk-2
	${INSTALL_DATA_DIR} ${PALMDEV}/sdk-3.1
	cd ${WRKDIR}/sdk-3.1 && ${PAX} -rw include ${PALMDEV}/sdk-3.1
	${INSTALL_DATA_DIR} ${PALMDEV}/sdk-3.5/include
	cd ${WRKDIR}/Palm\ OS\ 3.5\ Support/Incs \
		&& ${PAX} -rw . ${PALMDEV}/sdk-3.5/include
	${INSTALL_DATA_DIR} ${PALMDEV}/sdk-3.5/lib
	cd ${WRKDIR}/Palm\ OS\ 3.5\ Support/GCC\ Libraries \
		&& ${PAX} -rw . ${PALMDEV}/sdk-3.5/lib
	cd ${PALMDEV} && ${LN} -s sdk-${PALMOS_DEFAULT_SDK} sdk

.include "../../mk/bsd.pkg.mk"
