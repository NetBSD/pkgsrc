# $NetBSD: Makefile,v 1.45 2012/10/03 00:20:18 asau Exp $
#

DISTNAME=	uudeview-0.5.20
PKGNAME=	uulib-0.5.20
PKGREVISION=	5
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fpx.de/fp/Software/UUDeview/
COMMENT=	Library for uu/xx/Base64/BinHex de-/encoding

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	uulib
BUILD_DIRS=	uulib
USE_LIBTOOL=	yes

BUILD_TARGET=	libuu.la

DOCFILES=	HISTORY doc/Makefile doc/README doc/binhex.fig \
		doc/library.ltx doc/structure.fig doc/td-v1.c doc/td-v2.c \
		doc/td-v3.c doc/test.txt

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3 share/doc/uulib

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/uulib/libuu.la \
		${DESTDIR:Q}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/uulib/uudeview.h ${DESTDIR:Q}${PREFIX}/include
	${SED} -e 's|FUNKYTOKENHERE|${PREFIX}|g' \
		< ${FILESDIR}/uulib.3 > ${WRKSRC}/uulib.3
	${INSTALL_MAN} ${WRKSRC}/uulib.3 ${DESTDIR:Q}${PREFIX}/${PKGMANDIR}/man3
.for docfile in ${DOCFILES}
	@${INSTALL_MAN} ${WRKSRC}/${docfile} \
		${DESTDIR:Q}${PREFIX}/share/doc/uulib
.endfor

.include "../../mk/bsd.pkg.mk"
