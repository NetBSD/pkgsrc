# $NetBSD: Makefile,v 1.9 2000/05/02 23:35:55 jlam Exp $
#

# According to AbiSource's explanation of their trademark rights,
# compilations/distributions of AbiWord not provided by AbiSource must
# be named "AbiWord Personal" or some name completely unlike AbiSource's
# registered trademarks.
#
DISTNAME=	abi-${ABIWORD_VERS}
PKGNAME=	abiword-personal-${ABIWORD_VERS}
ABIWORD_VERS=	0.7.9
CATEGORIES=	editors
MASTER_SITES=	http://www.abisource.com/downloads/Version-${ABIWORD_VERS}/lf/
DISTFILES=	${ABISRC} ${ABIDISTFILES} ${EXPATSRC} ${ICONVSRC} \
		${UNIXFONTS} ${WVSRC}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.abisource.com/

BUILD_DEPENDS+=	${LOCALBASE}/bin/unzip:../../archivers/unzip
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	png>=1.0.6:../../graphics/png
DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_X11=	# defined
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

CPPFLAGS+=	-I${LOCALBASE}/include				# png.h
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib	# -lpng

MAKE_ENV+=	ABI_BUILD_VERSION="${ABIWORD_VERS}" \
		OS_CFLAGS="${CPPFLAGS}" \
		OS_DLLFLAGS="${LDFLAGS}"

.include "../../mk/bsd.pkg.mk"
