# $NetBSD: Makefile,v 1.25 2001/05/22 09:32:18 wiz Exp $
#
# According to AbiSource's explanation of their trademark rights,
# compilations/distributions of AbiWord not provided by AbiSource must
# be named "AbiWord Personal" or some name completely unlike AbiSource's
# registered trademarks.

DISTNAME=	abi-${ABIWORD_VERS}
PKGNAME=	abiword-personal-${ABIWORD_VERS}
ABIWORD_VERS=	0.7.10
CATEGORIES=	editors
MASTER_SITES=	http://download.abisource.com/releases/${ABIWORD_VERS}/src/lf/
DISTFILES=	${ABISRC} ${ABIDISTFILES} ${EXPATSRC} ${ICONVSRC} \
		${UNIXFONTS} ${WVSRC}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.abisource.com/
COMMENT=	Open Source cross-platform word processor

BUILD_DEPENDS+=	unzip-*:../../archivers/unzip
DEPENDS+=	ispell-base-*:../../textproc/ispell-base
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	png>=1.0.11:../../graphics/png

USE_X11=	# defined
USE_XPM=	# defined
USE_GMAKE=	# defined
NO_CONFIGURE=	# defined
ALL_TARGET=	compile canonical

DIST_SUBDIR=	abisuite
ABISRC=		${DISTNAME}${EXTRACT_SUFX}
ABIDISTFILES=	abidistfiles-${ABIWORD_VERS}${EXTRACT_SUFX}
EXPATSRC=	expat-${ABIWORD_VERS}${EXTRACT_SUFX}
ICONVSRC=	libiconv-${ABIWORD_VERS}${EXTRACT_SUFX}
UNIXFONTS=	unixfonts-${ABIWORD_VERS}${EXTRACT_SUFX}
WVSRC=		wv-${ABIWORD_VERS}${EXTRACT_SUFX}

# Avoid headers from some installed packages.  These must come first!
CPPFLAGS+=	-I${WRKDIR}/wv
CPPFLAGS+=	-I${WRKDIR}/libiconv/include

CPPFLAGS+=	-I${LOCALBASE}/include		# png.h

MAKE_ENV+=	ABI_BUILD_VERSION="${ABIWORD_VERS}"
MAKE_ENV+=	OS_EXTRA_CFLAGS="${CPPFLAGS}"
MAKE_ENV+=	OS_DLLFLAGS="${LDFLAGS}"

post-install:
	${CHMOD} -R a+r ${PREFIX}/share/AbiSuite
	${RM} -f ${PREFIX}/share/AbiSuite/dictionary/american.hash
	${LN} -sf ../../../lib/american.hash ${PREFIX}/share/AbiSuite/dictionary/american.hash

.include "../../mk/bsd.pkg.mk"
