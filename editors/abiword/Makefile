# $NetBSD: Makefile,v 1.13 2000/11/22 13:19:41 abs Exp $
#

# According to AbiSource's explanation of their trademark rights,
# compilations/distributions of AbiWord not provided by AbiSource must
# be named "AbiWord Personal" or some name completely unlike AbiSource's
# registered trademarks.
#
DISTNAME=	abi-${ABIWORD_VERS}
PKGNAME=	abiword-personal-${ABIWORD_VERS}
ABIWORD_VERS=	0.7.10
CATEGORIES=	editors
MASTER_SITES=	http://download.abisource.com/releases/${ABIWORD_VERS}/src/lf/
DISTFILES=	${ABISRC} ${ABIDISTFILES} ${EXPATSRC} ${ICONVSRC} \
		${UNIXFONTS} ${WVSRC}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.abisource.com/

BUILD_DEPENDS+=	${LOCALBASE}/bin/unzip:../../archivers/unzip
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	png>=1.0.6:../../graphics/png

USE_X11=	YES
USE_XPM=	YES
USE_GMAKE=	YES
NO_CONFIGURE=	YES
ALL_TARGET=	compile canonical

DIST_SUBDIR=	abisuite
ABISRC=		${DISTNAME}${EXTRACT_SUFX}
ABIDISTFILES=	abidistfiles-${ABIWORD_VERS}${EXTRACT_SUFX}
EXPATSRC=	expat-${ABIWORD_VERS}${EXTRACT_SUFX}
ICONVSRC=	libiconv-${ABIWORD_VERS}${EXTRACT_SUFX}
UNIXFONTS=	unixfonts-${ABIWORD_VERS}${EXTRACT_SUFX}
WVSRC=		wv-${ABIWORD_VERS}${EXTRACT_SUFX}

CPPFLAGS+=	-I${WRKDIR}/wv 		# avoid using installed wv includes
CPPFLAGS+=	-I${LOCALBASE}/include				# png.h
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib	# -lpng

MAKE_ENV+=	ABI_BUILD_VERSION="${ABIWORD_VERS}" \
		OS_CFLAGS="${CPPFLAGS}" \
		OS_DLLFLAGS="${LDFLAGS}"

post-install:
	${CHMOD} -R a+r ${PREFIX}/share/AbiSuite

.include "../../mk/bsd.pkg.mk"
