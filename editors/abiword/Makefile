# $NetBSD: Makefile,v 1.1.1.1 1999/09/11 18:27:48 jlam Exp $
#

DISTNAME=	abi-${ABIWORD_VERS}
PKGNAME=	abiword-personal-${ABIWORD_VERS}
ABIWORD_VERS=	0.7.5
CATEGORIES=	editors
MASTER_SITES=	http://www.abisource.com/downloads/Version-${ABIWORD_VERS}/lf/
DISTFILES=	${ABISRC} ${ABIDISTFILES} ${UNIXFONTS} ${EXPATSRC} ${WVSRC}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.abisource.com/

BUILD_DEPENDS+=	${LOCALBASE}/bin/unzip:../../archivers/unzip
DEPENDS+=	gtk+-1.2.4:../../x11/gtk
DEPENDS+=	png-1.0.3:../../graphics/png

USE_X11=	yes
USE_GMAKE=	yes
NO_CONFIGURE=	yes
ALL_TARGET=	canonical

DIST_SUBDIR=	abisuite
ABISRC=		${DISTNAME}${EXTRACT_SUFX}
ABIDISTFILES=	abidistfiles-${ABIWORD_VERS}${EXTRACT_SUFX}
UNIXFONTS=	unixfonts-${ABIWORD_VERS}${EXTRACT_SUFX}
EXPATSRC=	expat-${ABIWORD_VERS}${EXTRACT_SUFX}
WVSRC=		wv-${ABIWORD_VERS}${EXTRACT_SUFX}

ABISUITE_HOME=		${PREFIX}/share/AbiSuite
ABISUITE_LIBEXEC=	${PREFIX}/libexec/AbiSuite

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
ZLIB_DIR=	${LOCALBASE}/lib
LDFLAGS+=	-L${ZLIB_DIR}
.endif

LIBPNG_DIR=	${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LIBPNG_DIR}

MAKE_ENV+=	MACHINE_ARCH="${MACHINE_ARCH}" \
		ABISUITE_HOME="${ABISUITE_HOME}" \
		ABISUITE_LIBEXEC="${ABISUITE_LIBEXEC}" \
		ZLIB_DIR="${ZLIB_DIR}" \
		LIBPNG_DIR="${LIBPNG_DIR}" \
		OS_CFLAGS="${CPPFLAGS}" \
		OS_DLLFLAGS="${LDFLAGS}"

post-patch:
	${MKDIR} ${WRKSRC}/src/pkg/netbsd
	${CP} ${FILESDIR}/GNUMakefile.install ${WRKSRC}/src/pkg/netbsd/Makefile

.include "../../mk/bsd.pkg.mk"
