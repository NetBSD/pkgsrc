# $NetBSD: Makefile,v 1.36 2006/01/20 14:54:03 tv Exp $
#

DISTNAME=       uudeview-0.5.20
PKGNAME=        uulib-0.5.20
PKGREVISION=	3
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fpx.de/fp/Software/UUDeview/
COMMENT=	Library for uu/xx/Base64/BinHex de-/encoding

# "kdesupport-2.1b" included "uu" library.
CONFLICTS+=	kdesupport-2.1b

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	uulib
BUILD_DIRS=	uulib
USE_LIBTOOL=	yes

BUILD_TARGET=	libuu.la

DOCFILES=	HISTORY doc/Makefile doc/README doc/binhex.fig \
		doc/library.ltx doc/structure.fig doc/td-v1.c doc/td-v2.c \
		doc/td-v3.c doc/test.txt

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	include lib man/man3

do-install:
	${LIBTOOL} ${INSTALL_LIB} ${WRKSRC}/uulib/libuu.la ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/uulib/uudeview.h ${PREFIX}/include
	${SED} -e 's|FUNKYTOKENHERE|${PREFIX}|g' \
		< ${FILESDIR}/uulib.3 > ${WRKSRC}/uulib.3
	${INSTALL_MAN} ${WRKSRC}/uulib.3 ${PREFIX}/man/man3
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uulib
.for docfile in ${DOCFILES}
	@${INSTALL_MAN} ${WRKSRC}/${docfile} ${PREFIX}/share/doc/uulib
.endfor

.include "../../mk/bsd.pkg.mk"
