# $NetBSD: Makefile,v 1.26 2001/05/24 04:28:19 jlam Exp $
#
# According to AbiSource's explanation of their trademark rights,
# compilations/distributions of AbiWord not provided by AbiSource must
# be named "AbiWord Personal" or some name completely unlike AbiSource's
# registered trademarks.

DISTNAME=	abi-${ABIWORD_VERS}
PKGNAME=	abiword-personal-${ABIWORD_VERS}
ABIWORD_VERS=	0.7.14
CATEGORIES=	editors
MASTER_SITES=	http://www.abisource.com/downloads/Version-${ABIWORD_VERS}/
DIST_SUBDIR=	abisuite
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	abidistfiles-${ABIWORD_VERS}${EXTRACT_SUFX}
DISTFILES+=	expat-${ABIWORD_VERS}${EXTRACT_SUFX}
DISTFILES+=	psiconv-${ABIWORD_VERS}${EXTRACT_SUFX}
DISTFILES+=	unixfonts-${ABIWORD_VERS}${EXTRACT_SUFX}
DISTFILES+=	wv-${ABIWORD_VERS}${EXTRACT_SUFX}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.abisource.com/
COMMENT=	Open Source cross-platform word processor

BUILD_DEPENDS+=	unzip-*:../../archivers/unzip
DEPENDS+=	libiconv>=1.5:../../converters/libiconv
DEPENDS+=	ispell-base-*:../../textproc/ispell-base
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	png>=1.0.11:../../graphics/png

USE_X11=	# defined
USE_XPM=	# defined
USE_GMAKE=	# defined
NO_CONFIGURE=	# defined
ALL_TARGET=	compile canonical

OS_CFLAGS=	${CFLAGS}

.if exists(/usr/include/inttypes.h)
OS_CFLAGS+=	-DHAVE_INTTYPE_H=1
.endif

# Avoid headers from some installed packages.  These must come first before
# ${LOCALBASE}/include!
#
OS_CFLAGS+=	-I${WRKDIR}/expat
OS_CFLAGS+=	-I${WRKDIR}/psiconv
OS_CFLAGS+=	-I${WRKDIR}/wv

OS_CFLAGS+=	-I${LOCALBASE}/include	# png.h & iconv.h

# AbiWord expects the iconv functions to be in the system libraries, so
# unconditionally link against the pkgsrc libiconv.so.
#
XLDFLAGS=	${LDFLAGS} -liconv

MAKE_ENV+=	OS_CFLAGS="${OS_CFLAGS}"
MAKE_ENV+=	XLDFLAGS="${XLDFLAGS}"

MAKE_FLAGS+=	ABI_BUILD_VERSION="${ABIWORD_VERS}"
MAKE_FLAGS+=	UNIX_CAN_BUILD_STATIC=0

WRKSRC=		${WRKDIR}/abi

post-extract:
	${RM} -rf ${WRKSRC}/user/wp/help/images/CVS

post-install:
	${CHMOD} -R a+r ${PREFIX}/share/AbiSuite
	${RM} -f ${PREFIX}/share/AbiSuite/dictionary/american.hash
	${LN} -sf ../../../lib/american.hash				\
		${PREFIX}/share/AbiSuite/dictionary/american.hash

.include "../../mk/bsd.pkg.mk"
