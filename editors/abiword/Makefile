# $NetBSD: Makefile,v 1.20 2001/05/01 12:45:56 rh Exp $
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
DEPENDS+=	libiconv>=1.6.1:../../converters/libiconv
DEPENDS+=	ispell-base-*:../../textproc/ispell-base
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	png>1.0.9:../../graphics/png

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
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib -liconv

MAKE_ENV+=	ABI_BUILD_VERSION="${ABIWORD_VERS}" \
		OS_CFLAGS="${CPPFLAGS}" \
		OS_DLLFLAGS="${LDFLAGS}"

post-install:
	${CHMOD} -R a+r ${PREFIX}/share/AbiSuite
	rm ${PREFIX}/share/AbiSuite/dictionary/american.hash
	ln -s ../../../lib/american.hash ${PREFIX}/share/AbiSuite/dictionary/american.hash

.include "../../mk/bsd.pkg.mk"
