# $NetBSD: Makefile,v 1.28 2004/04/23 22:49:12 snj Exp $
#

DISTNAME=       uudeview-0.5.20
PKGNAME=        uulib-0.5.20
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fpx.de/fp/Software/UUDeview/
COMMENT=	Library for uu/xx/Base64/BinHex de-/encoding

# "kdesupport-2.1b" included "uu" library.
CONFLICTS=	kdesupport-2.1b

WRKSRC=		${WRKDIR}/${DISTNAME}/uulib
USE_BUILDLINK3= yes
GNU_CONFIGURE=	# defined
USE_LIBTOOL=	# defined

ALL_TARGET=	libuu.la

DOCFILES=	HISTORY doc/Makefile doc/README doc/binhex.fig \
		doc/library.ltx doc/structure.fig doc/td-v1.c doc/td-v2.c \
		doc/td-v3.c doc/test.txt

.include "../../mk/bsd.prefs.mk"

do-install:
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/libuu.la ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/uudeview.h ${PREFIX}/include/uu.h
	${SED} -e 's|FUNKYTOKENHERE|${PREFIX}|g' \
		< ${FILESDIR}/uulib.3 > ${WRKSRC}/uulib.3
	${INSTALL_MAN} ${WRKSRC}/uulib.3 ${PREFIX}/man/man3
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uulib
.for docfile in ${DOCFILES}
	@${INSTALL_MAN} ${WRKSRC}/../${docfile} ${PREFIX}/share/doc/uulib
.endfor

.include "../../mk/bsd.pkg.mk"
